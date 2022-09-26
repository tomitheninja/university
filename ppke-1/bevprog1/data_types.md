# Data types

Here are the most common data types

I don't recommend using smaller or unsigned data types as they are a common source of errors.

If your program is slow, that's not because you use one extra megabyte. They are meant to be used in embedded systems or when you have hundreds of megabytes items in an vector.

## Primitives

### Characters

Stores a character of the english ABC or a common symbol or control character.

```c++
char c = 'A';
char dollar_sign = '$';
char new_line = '\n';
```

### Integers

| name       | min value     | max value     |
| :------------- | :----------: | -----------: |
|  int | -2 000 000 000   | +2 000 000 000    |

### The index type

Your editor might recommend using the `size_t` type for array access. It's your choice if you use int or size_t

### Real numbers

Remember: Equality does not work on real numbers

`0.1 + 0.2 == 0.30000000000000004`

Use `abs(a - b) < 0.0001` instead to check if a is close to b.

| name       | min value     | max value     |
| :------------- | :----------: | -----------: |
|  float | 0.0   | 2^255    | <- I recommend choosing this type
|  double | 0.0   | 2^255    | Can store a longer fraction 

### Boolean

Can store 'yes' or 'no'

Most commonly used as a condition for the `if`-s

```c++
bool is_happy = true;
bool is_monday = false;
```

## Complex types

### C style arrays

Just dont. They are obsolete.

### C++ vectors

Can store a list of numbers. Can be extended to any length.

unlike c arrays vectors do know their size and they behave as expected.

```c++
#include <vector>

vector<int> v;
v.push_back(10);
```

### strings

Basically a vector that stores characters, but have some additional built in functionality.

```c++
#include <string>

string s = "foo";
```
