#include <iostream> // input and output
#include <fstream>  // files
#include <vector>   // vector = c++'s better array
#include <string>   // vector like c++ strings
#include <cmath>    // math stuff like sqrt()
#include <cstdlib>  // rand
#include <ctime>    // time() to seed rand()

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

// Print the structure to a file in this format:
// {year}.{month}.{day}
ostream &operator<<(ostream &f, Date d)
{
    f << d.year << '.' << d.month << '.' << d.day;
    return f;
}

// Read the Date from an input
// which has the following format:
// {year}.{month}.{day}
istream &operator>>(istream &f, Date &d)
{
    char junk; // we will read the dots or any seperator character into this variable

    f >> d.year >> junk >> d.month >> junk >> d.day;
    return f;
}

bool operator<(Date a, Date b)
{
    if (a.year < b.year)
        return true;
    if (a.year > b.year)
        return false;
    // at this point a.year must be = b.year
    if (a.month < b.month)
        return true;
    if (a.month > b.month)
        return false;
    // at this point a.year must be == b.year && a.month must be == b.month
    return a.day < b.day;
}

bool operator>(Date a, Date b)
{
    if (a.year > b.year)
        return true;
    if (a.year < b.year)
        return false;
    // at this point a.year == b.year
    if (a.month > b.month)
        return true;
    if (a.month < b.month)
        return false;
    // at this point a.year == b.year && a.month == b.month
    return a.day > b.day;
}

bool operator==(Date a, Date b)
{
    return a.year == b.year && a.month == b.month && a.day == b.day;
}

int main()
{
    // EXAMPLE:
    Date d1;
    d1.year = 2020;
    d1.month = 11;
    d1.day = 24;

    ifstream f("date.txt");
    Date d2;
    f >> d2; // reading from input to Date is implemented on line 29
    f.close();

    // The parantheses are often needed if the expression is surrounded by << or >>.
    cout << (d1 < d2) << endl;
}
