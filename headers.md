# C++ header files

* iostream (console input-output stream)
* fstream (file stream)
* vector (a better array <- dynamic size)
* string (a better character array <- dynamic size)
* cmath (mathematical functions like sqrt() and abs())
* cstdlib (rand() and srand())
* ctime (time to seed rand() with)

C++ has terrible error messages so it's not trivial to notice that if you didn't include something the language needs.

So I recommend including all of these when you create a new file. Then remove the unused ones when you are done with the file.

```c++
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
```
