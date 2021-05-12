#include <iostream>
#include <cstring>

using namespace std;

int count_char(const char *s, char c)
{
    int many = 0;
    for (size_t i = 0; i < string(s).length(); i++)
    {
        if (s[i] == c)
        {
            many++;
        }
    }
    return many;
}

int main()
{
    // Haha CPU goes brrrr
    string s;
    getline(cin, s);

    char best_char = ' ';
    for (size_t i = 0; i < strlen(s.c_str()); i++)
    {
        int many_current = count_char(s.c_str(), s[i]);
        int many_best = count_char(s.c_str(), best_char);
        if (many_current > many_best)
        {
            best_char = s[i];
        }
    }

    if (count_char(s.c_str(), best_char) != 0)
    {
        cout << best_char << endl;
    }

    return 0;
}