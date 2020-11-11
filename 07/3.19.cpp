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
    int x;
    cin >> x;
    if (is_prime(x))
    {
        cout << "igaz" << endl;
    }
    else
    {
        cout << "hamis" << endl;
    }
}