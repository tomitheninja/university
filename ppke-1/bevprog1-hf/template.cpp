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

struct Valami
{
};

ostream &operator<<(ostream &os, Valami d)
{
    return os;
}

istream &operator>>(istream &is, Valami &d)
{
    char szemet;
    return is;
}

void beolvas(istream &is, vector<Valami> &v)
{
}

int main()
{
    vector<Valami> v;

    ifstream f("date.txt");
    beolvas(f, v);
    f.close();
}