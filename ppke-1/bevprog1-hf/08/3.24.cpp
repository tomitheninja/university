#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    string longest_line;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        if (s.length() > longest_line.length())
        {
            longest_line = s;
        }
    }

    cout << longest_line << endl;
    return 0;
}