#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hany(vector<int> v, double ez)
{
    return count(v.begin(), end(v), ez);
}