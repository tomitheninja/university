#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x, y;
    cin >> x;
    cin >> y;
    int sum_diff = abs(y - x);
    for (int i = 2; i < n; i++)
    {
        cin >> y;
        int diff = abs(y - x);
        sum_diff += diff;
    }
    cout << (double)sum_diff / (n - 1) << endl;
    return 0;
}