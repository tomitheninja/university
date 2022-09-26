// This is a home made date library.
// I don't promise anything, but it should work between 1600 and 9999.
// (see: https://en.wikipedia.org/wiki/Gregorian_calendar)
// You can read, print, compare dates and calculate the days between two dates using this library.

#include <iostream>
#include <cmath>

using namespace std;

// Stores a date with day precision
struct Date
{
    int year;
    int month;
    int day;
};

// Reads a date into the result parameter.
// The istream must have csv format
istream &operator>>(istream &is, Date &result)
{
    char szemet;
    is >> result.year >> szemet;
    is >> result.month >> szemet;
    is >> result.day;
    return is;
}

// prints the date in the following format:
// y.m.d
ostream &operator<<(ostream &os, Date &d)
{
    os << d.year << '.';
    os << d.month << '.';
    os << d.day;
    return os;
}

bool operator==(const Date &d1, const Date &d2)
{
    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

bool operator!=(const Date &d1, const Date &d2)
{
    return d1.year == d2.year || d1.month == d2.month || d1.day == d2.day;
}

bool operator<(const Date &d1, const Date &d2)
{
    if (d1.year < d2.year)
        return true;
    if (d1.year > d2.year)
        return false;
    // at this point d1.year must equal d2.year
    if (d1.month < d2.month)
        return true;
    if (d1.month > d2.month)
        return false;
    // at this point a.year == b.year && a.month == b.month
    return d1.day < d2.day;
}

bool operator>(const Date &d1, const Date &d2)
{
    if (d1.year > d2.year)
        return true;
    if (d1.year < d2.year)
        return false;
    // at this point a.year == b.year
    if (d1.month > d2.month)
        return true;
    if (d1.month < d2.month)
        return false;
    // at this point a.year == b.year && a.month == b.month
    return d1.day > d2.day;
}

// Returns how many days have passed since 1600.01.01
int get_datetime(const Date &d)
{
    int year = d.year;
    // Every 4th year is a leap year,
    // except when it is divisible by 100.
    // But every 400th year is a leap year.

    int from_year = year * 365 + (year / 4) - (year / 100) + (year / 400);

    // distance from January 1:
    // february 1 = 31 days
    // march 1 = february 1 + 28 days = 59 days
    // april 1 = march 1 + 31 days = 90 days
    // ...
    int m_to_d[]{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int from_month = m_to_d[d.month - 1];

    int from_day = d.day;

    // When the month is January or February, we are before the leap year
    bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || ((year + 300) % 400 == 0);
    bool is_before_leap_year = d.month <= 2;
    // fix: leap day is "January 0th"
    // this is a branch optimized version of this code:
    // if (is_leap_year && is_before_leap_year) daytime--;
    int from_leap = -(is_leap_year && is_before_leap_year);

    return from_year + from_month + from_day + from_leap;
}

// Returns the difference between two dates as days
int operator-(const Date &d1, const Date &d2)
{
    return get_datetime(d1) - get_datetime(d2);
}

int main()
{
    Date d1, d2;
    // You can read into dates from an input source
    // as long as it has the correct format
    cin >> d1;
    cin >> d2;
    int diff_in_days = abs(d1 - d2);
    cout << diff_in_days << endl;
}
