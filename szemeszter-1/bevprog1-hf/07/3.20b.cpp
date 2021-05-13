#include <iostream>

using namespace std;

bool is_prime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return x > 1;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 2; i < k; i++)
    {
        if (is_prime(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}