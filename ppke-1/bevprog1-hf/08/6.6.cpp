#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vane(vector<int> v, int ez)
{
    return find(v.begin(), end(v), ez) != end(v);
}