#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int min, max;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0 || x < min)
        {
            min = x;
        }
        if (i == 0 || x > max)
        {
            max = x;
        }
    }
    cout << min << ' ' << max << endl;
    return 0;
}