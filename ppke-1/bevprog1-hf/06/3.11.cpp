#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num_even = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            num_even++;
        }
    }
    cout << num_even << endl;
    return 0;
}