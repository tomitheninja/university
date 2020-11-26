#include <iostream> // input and output
#include <cmath>    // math stuff like sqrt()
#include <cstdlib>  // rand
#include <ctime>    // time()

using namespace std;

// Returns a random integer value
// from the
// [0 <= start, end[
// range. (start >= 0; start < end; can't return end)
int rand_range(int start, int end)
{
    return start + rand() % end;
}

// Returns a signed random integer value
// from the [start, end[ range.
// start and end can be negative.
int rand_srange(int start, int end)
{
    // Shift the range to the not negative interval.
    // [start, end[ -> [0, length(start, end)[
    int rng_len = abs(end - start);
    // generate a number on this new range
    int unsigned_result = rand_range(0, rng_len); // same as rand() % rng_len
    // then shift it back
    return unsigned_result + start;
}

int main()
{
    // Seed the random number generator with the current time
    // So it will generate different random numbers
    // every time the user runs the program
    srand(time(NULL));
  
    // EXAMPLE:
    int age = rand_range(14, 120);

    if (age < 14)
    {
        cout << "You should use lego only while your parents are watching" << endl;
    }
    else if (age < 16)
    {
        cout << "Have fun!" << endl;
    }
    else if (age < 25)
    {
        cout << "You should study" << endl;
    }
    else if (age < 99)
    {
        cout << "You should work" << endl;
    }
    else
    {
        cout << "Sorry, you are too old to play with lego!" << endl;
    }
}
