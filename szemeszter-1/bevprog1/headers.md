# C++ header files

* iostream (console input-output stream)
* fstream (file stream)
* vector (a better array <- dynamic size)
* string (a better character array <- dynamic size)
* cmath (mathematical functions like sqrt() and abs())
* cstdlib (rand() and srand())
* ctime (time to seed rand() with)
* algorithm (pre-written functions like find and sort)

C++ has terrible error messages so it's not trivial to notice when you didn't include something your program uses.

I recommend including all of these, when you create a new file. Then remove the unused ones when you are done working.

```c++
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
// helpers for algorithm:
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

int main()
{
    return 0;
}
```
