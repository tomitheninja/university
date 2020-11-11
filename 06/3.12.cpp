#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int min = n;
    int max = n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < min)
        {
            min = x;
        }
        if (x > max)
        {
            max = x;
        }
    }
    cout << min << endl;
    cout << max << endl;
    return 0;
}