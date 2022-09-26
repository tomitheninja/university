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

string remove_useless_whitespace(string s)
{
    string result = "";
    for (int i = 0; i < s.size() - 1; i++)
    {
        bool is_double_whitespace = isspace(s[i]) && isspace(s[i + 1]);
        if (!is_double_whitespace)
        {
            result += s[i];
        }
    }
    result += s[s.size() - 1];
    return result;
}

