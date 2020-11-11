#include <iostream>

using namespace std;

int largest_divisor(int x)
{
    for (int i = x - 1; i >= 2; i--)
    {
        if (x % i == 0)
        {
            return i;
        }
    }
    // Does not exist
    return -1;
}

int main()
{
    int n;
    cin >> n;
    cout << largest_divisor(n) << endl;
    return 0;
}