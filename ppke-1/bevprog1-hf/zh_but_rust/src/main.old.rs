use rayon::prelude::*;
use chrono::NaiveDate;
use serde::Deserialize;
use ustr::{Ustr, UstrSet};

#[derive(Debug, Deserialize, Clone, PartialEq)]
struct Record {
    #[serde(with = "date_parser", rename = "date")]
    date: NaiveDate,
    #[serde(rename = "countriesAndTerritories")]
    fullname: Ustr,
    #[serde(rename = "geoId")]
    geo_id: Ustr,
    #[serde(rename = "countryterritoryCode")]
    country_code: Ustr,
    #[serde(rename = "continentExp")]
    continent: Ustr,
    #[serde(rename = "popData2019")]
    population: i32,
    cases: i32,
    deaths: i32,
    #[serde(rename = "Cumulative_number_for_14_days_of_COVID-19_cases_per_100000")]
    cumulative: f32,
}

mod date_parser {
    use chrono::NaiveDate;
    use serde::{self, de::Error, Deserialize, Deserializer};

    pub fn deserialize<'de, D>(deserializer: D) -> Result<NaiveDate, D::Error>
    where
        D: Deserializer<'de>,
    {
        let s = String::deserialize(deserializer)?;
        NaiveDate::parse_from_str(&s, "%Y.%m.%d.").map_err(Error::custom)
    }
}

fn main() {
    let mut reader = csv::Reader::from_path("data.csv").unwrap();

    let mut data = Vec::with_capacity(50_000);

    for result in reader.deserialize() {
        let result: Record = result.unwrap();
        data.push(result);
    }

    println!("{}", data.iter().map(|x| x.cases).sum::<i32>());

    let europe = Ustr::from("Europe");

    eprintln!("################################ 1. feladat ################################");

    data.iter()
        .filter(|x| x.continent == europe)
        .filter(|x| x.deaths > 100)
        .map(|x| x.fullname)
        .collect::<UstrSet>()
        .iter()
        .for_each(|x| println!("{}", x));
    
    eprintln!("################################ 2. feladat ################################");

    let more_than_200: UstrSet = data
        .iter()
        .filter(|x| x.continent == europe)
        .filter(|x| x.cases > 200)
        .map(|x| x.fullname)
        .collect();

    let result = data
        .iter()
        .filter(|x| x.continent == europe)
        .filter(|x| !more_than_200.contains(&x.fullname))
        .min_by_key(|x| x.population)
        .unwrap();

    println!("{}", result.fullname);

    eprintln!("################################ 3. feladat ################################");

    let continents: UstrSet = data.iter().map(|x| x.continent).collect();

    continents.iter().for_each(|continent| {
        let sum_cases: i64 = data
            .iter()
            .filter(|x| x.continent == *continent)
            .map(|x| x.cases as i64)
            .sum();
        println!("{} had {} total cases", continent, sum_cases);
    });

    eprintln!("################################ 4. feladat ################################");

    let countries: UstrSet = data.iter().map(|x| x.fullname).collect();

    let result = countries
        .par_iter()
        .map(|country| {
            let mut reports: Vec<_> = data.iter().filter(|x| x.fullname == *country).collect();
            reports.sort_by_key(|x| x.date);
            (country, reports)
        })
        .filter(|(_, reports)| reports.len() > 1)
        .map(|(country, reports)| {
            let max_diff = reports
                .windows(2)
                .map(|x| (x, x[1].date.signed_duration_since(x[0].date)))
                .max_by_key(|&(_, diff)| diff)
                .unwrap()
                .1;
            (country, max_diff)
        }).max_by_key(|&(_, max_diff)| max_diff).unwrap();
    
    println!("{} {}", result.0, result.1.num_days());
}
