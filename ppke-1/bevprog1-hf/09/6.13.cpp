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

float terulet(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float magassag(float a, float b, float c, float &ma, float &mb, float &mc)
{
    float t = terulet(a, b, c);
    ma = t / a;
    mb = t / b;
    mc = t / c;
}
