#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(vector<int> v)
{
    return *max_element(v.begin(), end(v));
}