#include <iostream>
#include <vector>

using namespace std;

double dot(const vector<double> &v1, const vector<double> &v2)
{
    double sum = 0;
    for (size_t i = 0; i < v1.size(); i++)
    {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<double> v1;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        v1.push_back(x);
    }

    vector<double> v2;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        v2.push_back(x);
    }
    cout << dot(v1, v2) << endl;
    return 0;
}