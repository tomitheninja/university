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
    // Shift the range to the not negative [0, rng_len] interval.
    int rng_len = abs(end - start);
    // generate a number on this range
    int unsigned_result = rand_range(0, rng_len); // same as rand() % rng_len
    // then shift it back
    return unsigned_result + start;
}

// Generates a real number
// between 0 and 1 (can't be 1)
float rand_float()
{
    // We don't want to use integer division
    // (int)2 / (int)5 = (int)0
    // because then the result is also an int
    // This is done by cutting out the fractional part
    // and only saving the integer part of the real number
    // So a number between 0 and 0.999 will always become 0
    // when converted to an integer
    
    // But it works as expected when using real number types (like float)
    // (float)2.0 / (float)5.0 = (float)0.4
    // And yes using only one conversion would be enough,
    // because c++ automatically converts the other to real number
    // but I like this format, because it's more verbose.
    return (float)rand() / (float)RAND_MAX;
}

int main()
{
    // Seed the random number generator with the current time
    // So it will generate different random numbers
    // every time someone runs your program
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
        cout << "Sorry, but you are too old to play with lego!" << endl;
    }
}
