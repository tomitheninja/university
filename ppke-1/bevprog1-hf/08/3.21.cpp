#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int many = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            many++;
        }
    }
    cout << many << endl;
    return 0;
}