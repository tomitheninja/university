#include <iostream>
#include <cmath>

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

    int many = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (is_prime(x))
        {
            many++;
        }
    }
    cout << many << endl;
    return 0;
}