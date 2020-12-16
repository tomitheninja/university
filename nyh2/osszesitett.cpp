#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

// ---------------------------------------------------------------- Date

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

// prints the date in a human-readable format
ostream &operator<<(ostream &os, Date &d)
{
    os << d.year << '.';
    os << d.month << '.';
    os << d.day << '.';
    return os;
}

bool operator<(Date a, Date b)
{
    if (a.year < b.year)
        return true;
    if (a.year > b.year)
        return false;
    if (a.month < b.month)
        return true;
    if (a.month > b.month)
        return false;
    return a.day < b.day;
}

bool operator>(Date a, Date b)
{
    if (a.year > b.year)
        return true;
    if (a.year < b.year)
        return false;
    if (a.month > b.month)
        return true;
    if (a.month < b.month)
        return false;
    return a.day > b.day;
}

bool operator!=(Date a, Date b)
{
    return a.year != b.year || a.month != b.month || a.day != b.day;
}

bool operator==(Date a, Date b)
{
    return a.year == b.year || a.month == b.month || a.day == b.day;
}

// Returns the date which follows the given date
Date add_one_day(Date d)
{
    d.day++;
    switch (d.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d.day == 31 + 1)
        {
            d.day = 1;
            d.month++;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (d.day == 30 + 1)
        {
            d.day = 1;
            d.month++;
        }
        break;
    case 2:
        if (d.year % 4 == 0)
        {
            if (d.day == 29 + 1)
            {
                d.day = 1;
                d.month++;
            }
        }
        else
        {
            if (d.day == 28 + 1)
            {
                d.day = 1;
                d.month++;
            }
        }
    }
    if (d.month == 13)
    {
        d.year++;
        d.month = 1;
    }
    return d;
}

// Returns the number of days between the two days
int operator-(Date d1, Date d2)
{
    int sign = 1;
    if (d2 < d1)
    {
        Date tmp = d2;
        d2 = d1;
        d1 = tmp;
        sign = -1;
    }
    int days;
    for (days = 0; d1 != d2; days++)
    {
        d1 = add_one_day(d1);
    }
    return sign * days;
}

// ---------------------------------------------------------------- Measurement

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

// ---------------------------------------------------------------- task no. 1

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

// ---------------------------------------------------------------- groups

// Collects the names of the continents
set<string> list_continents(const vector<Measurement> &v)
{
    set<string> result;
    for (Measurement m : v)
    {
        result.insert(m.continent_exp);
    }
    return result;
}

// Collects the name of the countries
set<string> list_countries(const vector<Measurement> &v)
{
    set<string> result;
    for (Measurement m : v)
    {
        result.insert(m.fullname);
    }
    return result;
}

// ---------------------------------------------------------------- find data

// Returns a measurement for the given country
Measurement country_by_fullname(const vector<Measurement> &v, string fullname)
{
    return *find_if(v.begin(), v.end(), [&](const Measurement &m) {
        return m.fullname == fullname;
    });
}

// ---------------------------------------------------------------- task no. 2

// Names of european countries with less than 200 deaths on any day
// returns: A set with all these countries's fullnames
set<string> less_than_200_cases_in_eu(const vector<Measurement> &v)
{
    set<string> results = list_countries(v);

    for (Measurement x : v)
    {
        if (x.continent_exp != "Europe" || x.cases > 200)
        {
            results.erase(x.fullname);
        }
    }
    return results;
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

// ---------------------------------------------------------------- task no. 3

int sum_cases_of_continent(const vector<Measurement> &v, string continent)
{
    int sum = 0;
    for (Measurement m : v)
    {
        if (m.continent_exp == continent)
        {
            sum += m.cases;
        }
    }
    return sum;
}

// ---------------------------------------------------------------- task no. 4

int legnagyobb_kihagyas(const vector<Measurement> &v, Measurement &max_start, Measurement &max_end)
{
    int max_diff = 0;
    bool is_first_max_diff = true;
    Measurement prev;
    Date prev_date = v[0].date;
    string prev_c = v[0].fullname;

    for (Measurement m : v)
    {
        if (m.fullname == prev_c)
        {
            int diff = abs(m.date - prev_date);
            if (is_first_max_diff || max_diff < diff)
            {
                max_diff = diff;
                is_first_max_diff = false;
                max_start = prev;
                max_end = m;
            }
        }
        prev_c = m.fullname;
        prev_date = m.date;
        prev = m;
    }
    return max_diff;
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

    {
        cerr << "### 1. feladat ###" << endl;
        for (string fullnames : more_than_100_eu_deaths(v))
        {
            cout << fullnames << endl;
        }
    }

    {
        cerr << "### 2. feladat ###" << endl;
        cout << feladat_2(v) << endl;
    }

    {
        cerr << "### 3. feladat ###" << endl;
        for (string continent : list_continents(v))
        {
            cout << continent << " : " << sum_cases_of_continent(v, continent) << endl;
        }
    }

    {
        cerr << "### 4. feladat ###" << endl;
        Measurement m_start;
        Measurement m_end;
        int diff_in_days = legnagyobb_kihagyas(v, m_start, m_end);
        cout << "A legnagyobb kihagyás " << m_start.fullname << "-ben volt" << endl;
        cout << "Kezdete: " << m_start.date << endl;
        cout << "Vége: " << m_end.date << endl;
        cout << "Hossza: " << diff_in_days << " nap" << endl;
    }
}