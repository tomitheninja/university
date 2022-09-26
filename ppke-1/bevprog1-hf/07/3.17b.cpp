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
    int the_dir = y < x;
    for (int i = 2; i < n; i++)
    {
        cin >> y;
        int its_dir = y < x;
        if (its_dir != the_dir)
        {
            cout << 0 << endl;
            return 0;
        }
        x = y;
    }
    cout << 1 << endl;
    return 0;
}