#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

struct Datum
{
    int ev;
    int ho;
    int nap;
};

istream &operator>>(istream &f, Datum &d)
{
    char szemet;

    f >> d.ev >> szemet >> d.ho >> szemet >> d.nap;
    return f;
}

ostream &operator<<(ostream &f, Datum d)
{
    f << d.ev << '.' << d.ho << '.' << d.nap;
    return f;
}

bool operator<(Datum a, Datum b)
{
    if (a.ev < b.ev)
        return true;
    if (a.ev > b.ev)
        return false;
    if (a.ho < b.ho)
        return true;
    if (a.ho > b.ho)
        return false;
    return a.nap < b.nap;
}

bool operator>(Datum a, Datum b)
{
    if (a.ev > b.ev)
        return true;
    if (a.ev < b.ev)
        return false;
    if (a.ho > b.ho)
        return true;
    if (a.ho < b.ho)
        return false;
    return a.nap > b.nap;
}

bool operator==(Datum a, Datum b)
{
    return a.ev == b.ev && a.ho == b.ho && a.nap == b.nap;
}

struct Nevjegy
{
    string nev;
    Datum szuletes;
};

istream &operator>>(istream &is, Nevjegy &n)
{
    getline(is, n.nev, ';');
    is >> n.szuletes;
    return is;
}

void beolvas(istream &is, vector<Nevjegy> &v)
{
    Nevjegy n;
    while (is >> n >> ws)
    {
        v.push_back(n);
    }
}

bool keres_t_szamot(vector<Nevjegy> v, string nev, Nevjegy &eredmeny)
{
    auto box = find_if(v.begin(), v.end(), [&](Nevjegy n) {
        return n.nev == nev;
    });
    if (box == v.end())
    {
        return false;
    }
    else
    {
        eredmeny = *box;
    }
}

bool keres_nev_alapjan(vector<Nevjegy> v, string nev, Nevjegy &eredmeny)
{
    auto box = find_if(v.begin(), v.end(), [&](Nevjegy n) {
        return n.nev == nev;
    });
    if (box == v.end())
    {
        return false;
    }
    eredmeny = *box;
}

Nevjegy legoregebb(vector<Nevjegy> v, string nev)
{
    return *max_element(v.begin(), v.end(), [](Nevjegy a, Nevjegy b) {
        return a.szuletes < b.szuletes;
    });
}

Nevjegy legfiatalabb(vector<Nevjegy> v, string nev)
{
    return *min_element(v.begin(), v.end(), [](Nevjegy a, Nevjegy b) {
        return a.szuletes < b.szuletes;
    });
}

vector<Nevjegy> nevsorba(vector<Nevjegy> v)
{
    sort(v.begin(), v.end(), [](Nevjegy a, Nevjegy b) {
        return a.nev < b.nev;
    });
    return v;
}

vector<Nevjegy> idosorba(vector<Nevjegy> v)
{
    sort(v.begin(), v.end(), [](Nevjegy a, Nevjegy b) {
        return a.szuletes < b.szuletes;
    });
    return v;
}

int main()
{
    vector<Nevjegy> szuletesek;

    ifstream f("szuletesek.csv");
    beolvas(f, szuletesek);
    f.close();

    string nev;
    getline(cin, nev);
    Nevjegy talalat;
    if (keres_nev_alapjan(szuletesek, nev, talalat))
    {
        cout << talalat.szuletes << endl;
    }
    else
    {
        cerr << "Nem találhato" << endl;
    }

    return 0;
}