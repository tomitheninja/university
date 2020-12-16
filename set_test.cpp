#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(1); // duplicate
    s.insert(2);
    s.insert(3);

    s.erase(2); // remove 2

    cout << "s contains:";
    for (int item : s)
    {
        cout << ' ' << item;
    }
    cout << endl;

    cout << "Has 1? " << s.count(1) << endl;
    cout << "Has 2? " << s.count(2) << endl;
    cout << "Has 3? " << s.count(3) << endl;
    cout << "Has 4? " << s.count(4) << endl;

    // copy the set into a vector
    vector<int> v;
    for (int item : s)
    {
        v.push_back(item);
    }
}