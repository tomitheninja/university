#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool is_inc = a < b && b < c;
    bool is_dec = c < b && b < a;

    if (is_inc || is_dec)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}