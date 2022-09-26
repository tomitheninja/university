#include <iostream>

using namespace std;

int count_divisors(int x)
{
    int sum = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << count_divisors(n) << endl;
    return 0;
}