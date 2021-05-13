#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double pro = 0;

    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        pro += a * b;
    }

    cout << pro << endl;
    return 0;
}