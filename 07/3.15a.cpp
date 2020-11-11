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
    int max_diff = y - x;
    for (int i = 2; i < n; i++)
    {
        cin >> y;
        int diff = y - x;
        if (diff > max_diff)
        {
            max_diff = diff;
        }
        x = y;
    }
    cout << max_diff << endl;
    return 0;
}