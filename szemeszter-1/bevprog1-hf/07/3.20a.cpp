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
    int n;
    cin >> n;
    int many_found = 0;
    for (int i = 2; many_found < n; i++)
    {
        if (is_prime(i))
        {
            many_found++;
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}