#include <iostream>

using namespace std;

int main()
{
    int n;
    int num_even = 0;
    while (cin >> n && n != 0)
    {
        if (n % 2 == 0)
        {
            num_even++;
        }
    }
    cout << num_even << endl;
    return 0;
}