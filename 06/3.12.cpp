#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int min_so_far = n;
    int max_so_far = n;
    while (cin >> n && n != 0)
    {
        if (n % 2 == 0)
        {
            min_so_far++;
        }
    }
    cout << min_so_far << endl;
    return 0;
}