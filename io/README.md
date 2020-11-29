# Input / Output algorithms

Note: The following algorithms aren't ordered by difficulty. Feel free to skip if you don't understand how it works and come back later.

Words I'll commonly use from here:

#### whitespace (ws)

any non visible character. Examples:
  * space (' ')
  * tab ('\t')
  * newline ('\n')
  * and many others
  
#### word like something (todo: what is this called??)

Something that doesn't contain any whitespace (I am sure there is a better synonym for it, but I haven't figured out that yet)

  * a is a word (and also a character)
  * 1 and 1.123 is a word (and a number)
  * apple and no_space_in_me is a word (strings without space inside them)
  
You can read words using the `>>` operator.
  
#### line

array of characters until the terminating '\n' (newline) character.

Might contain no or multiple words and whitespaces (just like lines in word)

You can read lines using `getline(source, to_str)`.

## Input algorithms

Always try to imagine you are moving the cursor in a file using the left and right arrows. C++ even provides reading/jumping over a word.

Make sure you included the required headers (iostream for console, fstream for files, string for strings)

### Reading one character

You can read into a variable that has `char` type using the `>>` operator. 

Will automatically **skip leading whitespaces**.

```c++
// read (visible) character from cin
char c;
cin >> c;
```

input (inside the ""-s) | value of c | location of the virtual cursor | explanation
--- | --- | --- | ---
"c" | 'c' | "c▶️" | We read the c character into the variable 
"apple" | 'a' | "a▶️pple" | We are reading only one character
"123" | '1' | "1▶️23" | '1' is a character, while 1 is a number. They are not even equal
" bar" | 'b' | " b▶️ar" | Will skip leading whitespaces
" ő " | nothing | " ő▶️ " | c++ does not support special characters, but will not crash (usually)

### Reading numbers

You can read into a variable that has `int` or `float` or any other numeric type using the `>>` operator. 

```c++
// read integer from cin
int n;
cin >> n;
```

```c++
// read float from cin
float n;
cin >> n;
```

type of n | input | value of n | location of the virtual cursor | explanation
--- | --- | --- | --- | ---
int | "123" | 123 | "123▶️" | -
float | "  123.456  " | 123.456 | "  123.456▶️  " | Will skip whitespace **BEFORE** the number
int | " 123.456 " | 123 | "  123▶️.456  " | int can't store fractions (.456), so it will stop if it finds a dot character.
any | "invalid" | it's previous value | ☠ | c++ can't convert the "invalid" string into a numeric value. This will crash the input stream which will only provide zero bytes from now on.
