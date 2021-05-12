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

struct Nevjegy
{
    string nev;
    string t_szam;
};

istream &operator>>(istream &is, Nevjegy &n)
{
    getline(is, n.nev, ';');
    getline(is, n.t_szam);
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

int main()
{
    vector<Nevjegy> t_konyv;

    ifstream f("telefonkonyv.txt");
    beolvas(f, t_konyv);
    f.close();

    string nev;
    getline(cin, nev);
    Nevjegy talalat;
    if (keres_t_szamot(t_konyv, nev, talalat))
    {
        cout << talalat.t_szam << endl;
    }
    else
    {
        cerr << "Nem található!" << endl;
    }

    return 0;
}