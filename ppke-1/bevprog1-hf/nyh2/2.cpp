#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

// Read a date
// from an istream
// which have the following format:
// year.month.day.
istream &operator>>(istream &is, Date &d)
{
    char szemet;

    is >> d.year >> szemet;
    is >> d.month >> szemet;
    is >> d.day >> szemet;
    return is;
}
struct Measurement
{
    Date date;
    string fullname;
    string geo_id;
    string territory_code;
    string continent_exp;
    int population;
    int cases;
    int deaths;
    float cumulative;
};

// Read a measurement from an istream with csv format
istream &operator>>(istream &is, Measurement &m)
{
    char junk;
    is >> m.date >> junk;
    getline(is, m.fullname, ',');
    getline(is, m.geo_id, ',');
    getline(is, m.territory_code, ',');
    getline(is, m.continent_exp, ',');
    is >> m.population >> junk;
    is >> m.cases >> junk;
    is >> m.deaths >> junk;
    is >> m.cumulative;
    return is;
}

// Loads and parses and content of the istream into the result vector
void beolvas(istream &is, vector<Measurement> &v)
{
    Measurement m;
    string header;
    getline(is, header);
    while (is >> m)
    {
        v.push_back(m);
        is >> ws;
    }
}

// Names of european countries with more than 100 deaths on one day
// returns: A set with all these countries's names
set<string> more_than_100_eu_deaths(const vector<Measurement> &v)
{
    set<string> result;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].continent_exp == "Europe" && v[i].deaths > 100)
        {
            result.insert(v[i].fullname);
        }
    }
    return result;
}

set<string> all_countries(const vector<Measurement> &v)
{
    set<string> result;
    for (Measurement m : v)
    {
        result.insert(m.fullname);
    }
    return result;
}

// Names of european countries with more than 100 deaths on one day
// returns: A set with all these countries's names
set<string> less_than_200_cases_in_eu(const vector<Measurement> &v)
{
    set<string> cs = all_countries(v);

    for (Measurement x : v)
    {
        if (x.continent_exp != "Europe" || x.cases > 200)
        {
            cs.erase(x.fullname);
        }
    }
    return cs;
}

// Returns a measururemnt for the given country
Measurement country_by_fullname(const vector<Measurement> &v, string fullname)
{
    return *find_if(v.begin(), v.end(), [&](const Measurement &m) {
        return m.fullname == fullname;
    });
}

// Names of european countries with more than 100 deaths on one day
// returns: A set with all these countries's names
string feladat_2(const vector<Measurement> &v)
{
    set<string> cs = less_than_200_cases_in_eu(v);
    Measurement best;
    bool first = true;
    for (string name : cs)
    {
        Measurement curr = country_by_fullname(v, name);
        if (first || best.population > curr.population)
        {
            best = curr;
        }
        first = false;
    }
    return best.fullname;
}

int main()
{
    vector<Measurement> v;
    v.reserve(50000);

    ifstream f("adatok.txt");
    if (!f.is_open())
    {
        cerr << "adatok.txt not found" << endl;
    }
    beolvas(f, v);
    f.close();

    cout << feladat_2(v) << endl;
}