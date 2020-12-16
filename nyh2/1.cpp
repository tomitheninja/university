#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// Stores a date with day precision
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
    char junk;

    is >> d.year >> junk;
    is >> d.month >> junk;
    is >> d.day >> junk;
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

// Names of european countries with more than 100 deaths on any day
// returns: A set with all these countries's fullnames
set<string> more_than_100_eu_deaths(const vector<Measurement> &v)
{
    set<string> result;
    for (int i = 0; i < v.size(); i++)
    {
        bool is_eu = v[i].continent_exp == "Europe";
        bool is_enough_death = v[i].deaths > 100;
        if (is_eu && is_enough_death)
        {
            result.insert(v[i].fullname);
        }
    }
    return result;
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

    for (string fullnames : more_than_100_eu_deaths(v))
    {
        cout << fullnames << endl;
    }

    cout << v[0].fullname << endl;
}