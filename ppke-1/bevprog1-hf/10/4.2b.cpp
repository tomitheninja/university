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

bool keres_nevet(vector<Nevjegy> v, string t_szam, Nevjegy &eredmeny)
{
    auto box = find_if(v.begin(), v.end(), [&](Nevjegy n) {
        return n.t_szam == t_szam;
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

    string t_szam;
    getline(cin, t_szam);
    Nevjegy talalat;
    if (keres_nevet(t_konyv, t_szam, talalat))
    {
        cout << talalat.nev << endl;
    }
    else
    {
        cerr << "Nem található!" << endl;
    }

    return 0;
}