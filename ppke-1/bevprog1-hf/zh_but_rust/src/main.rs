use chrono::NaiveDate;
use rayon::prelude::*;
use serde::Deserialize;
use ustr::{Ustr, UstrMap};

#[derive(Debug, Deserialize, Clone, PartialEq)]
struct RawRecord {
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
#[derive(Debug, Clone, PartialEq)]
struct Continent {
    name: Ustr,
    countries: UstrMap<Country>,
    sum_cases: i64,
    sum_deaths: i64,
}

#[derive(Debug, Clone, PartialEq, PartialOrd)]
struct Country {
    fullname: Ustr,
    geo_id: Ustr,
    country_code: Ustr,
    population: i32,
    reports: Vec<DailyReport>,
    sum_deaths: i32,
    max_deaths: i32,
    sum_cases: i32,
    max_cases: i32,
}

#[derive(Debug, Clone, PartialEq, PartialOrd)]
struct DailyReport {
    date: NaiveDate,
    cases: i32,
    deaths: i32,
    cumulative: f32,
}

fn main() {
    let mut world = UstrMap::default();
    world.reserve(5);

    let mut reader = csv::Reader::from_path("data.csv").unwrap();

    for report in reader.deserialize() {
        let report: RawRecord = report.unwrap();
        let continent = report.continent;
        if !world.contains_key(&continent) {
            world.insert(
                continent,
                Continent {
                    name: continent,
                    countries: UstrMap::default(),
                    sum_cases: 0,
                    sum_deaths: 0,
                },
            );
        }
        let continent = world.get_mut(&continent).unwrap();
        if !continent.countries.contains_key(&report.country_code) {
            continent.countries.insert(
                report.country_code,
                Country {
                    fullname: report.fullname,
                    geo_id: report.geo_id,
                    country_code: report.country_code,
                    population: report.population,
                    reports: Vec::new(),
                    max_cases: 0,
                    max_deaths: 0,
                    sum_cases: 0,
                    sum_deaths: 0,
                },
            );
        }
        let country = continent.countries.get_mut(&report.country_code).unwrap();
        country.reports.push(DailyReport {
            date: report.date,
            cases: report.cases,
            deaths: report.deaths,
            cumulative: report.cumulative,
        });
        country.sum_cases += report.cases;
        country.sum_deaths += report.deaths;
        country.max_cases = country.max_cases.max(report.cases);
        country.max_deaths = country.max_deaths.max(report.deaths);
        continent.sum_cases += report.cases as i64;
        continent.sum_deaths += report.deaths as i64;
    }

    let europe = Ustr::from("Europe");

    println!("############# task 1 #############");
    world
        .get(&europe)
        .unwrap()
        .countries
        .iter()
        .filter(|&(_, country)| country.max_deaths > 100)
        .for_each(|(_, country)| println!("{}", country.fullname));

    let task2_solution = world
        .get(&europe)
        .unwrap()
        .countries
        .iter()
        .filter(|&(_, country)| country.max_cases <= 200)
        .min_by_key(|&(_, country)| country.population)
        .unwrap()
        .1;

    println!();
    println!("############# task 2 #############");
    println!("{}", task2_solution.fullname);

    println!();
    println!("############# task 3 #############");
    world
        .iter()
        .for_each(|(_, continent)| println!("{} : {}", continent.name, continent.sum_cases));

    println!();
    println!("############# task 4 #############");

    let (country, ((start, end), len)) = world
        .iter()
        .map(|(_, continent)| {
            continent
                .countries
                .par_iter()
                .filter(|&(_, country)| country.reports.len() >= 2)
                .map(|(_, country)| {
                    let max_diff = country
                        .reports
                        .windows(2)
                        .map(|x| {
                            (
                                (x[0].date, x[1].date),
                                x[1].date.signed_duration_since(x[0].date),
                            )
                        })
                        .max_by_key(|&(_, diff)| diff)
                        .unwrap();
                    (country, max_diff)
                })
                .max_by_key(|(_, (_, len))| *len)
                .unwrap()
        })
        .max_by_key(|&(_, (_, len))| len)
        .unwrap();

    println!(
        "{} had no reports between {} and {} ({} days)",
        country.fullname,
        start,
        end,
        len.num_days()
    );
}
