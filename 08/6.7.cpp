#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

double atlag(vector<double> v)
{
    return accumulate(begin(v), end(v), 0.0) / v.size();
}