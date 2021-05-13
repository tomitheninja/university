#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int many_digit = 0;
    int many_lower = 0;
    int many_upper = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ('0' <= c && c <= '9')
        {
            many_digit++;
        }
        else if ('a' <= c && c <= 'z')
        {
            many_lower++;
        }
        else if ('A' <= c && c <= 'Z')
        {
            many_upper++;
        }
    }
    cout << many_digit << ' ' << many_lower << ' ' << many_upper << endl;
    return 0;
}