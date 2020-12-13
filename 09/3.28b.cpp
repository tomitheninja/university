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

void beolvas(vector<string> &v)
{
    int n;
    cin >> n >> ws;
    for (int i = 0; i < n; i++)
    {
        string sor;
        getline(cin, sor);
        v.push_back(sor);
    }
}

int hany_sor_alma(vector<string> &v)
{
    return count_if(v.begin(), v.end(), [](string line) {
        return line.find("alma") != string::npos;
    });
}

int hany_sor_ebbol(vector<string> &v, string mibol)
{
    return count_if(v.begin(), v.end(), [&](string line) {
        return line.find(mibol) != string::npos;
    });
}

int dekod(string s, string mibol)
{
    int hany = 0;
    while (s.find(mibol) != string::npos)
    {
        hany++;
        int pos = s.find(mibol);
        s = s.substr(pos + mibol.length());
    }
    return hany;
}

int hany_db_ebbol(vector<string> &v, string mibol)
{
    // Összegzés tétele, de "kódolva" van az adat
    return accumulate(v.begin(), v.end(), 0, [&](int hany_eddig, string s) {
        int hany_most = dekod(s, mibol);
        return hany_eddig + hany_most;
    });
}

int main()
{
    vector<string> v;
    string mibol;
    getline(cin, mibol);
    beolvas(v);
    cout << hany_sor_ebbol(v, mibol) << endl;
    return 0;
}
