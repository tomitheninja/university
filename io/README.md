# Input / Output algorithms

Note: The following algorithms aren't ordered by difficulty. Feel free to skip if you don't understand how it works and come back later.

Words I'll commonly use from here:

#### whitespace (ws)

A not visible character.

**Examples:**

  * space (' ')
  * tab ('\t')
  * newline ('\n')
  * and many others
  
#### word like something (todo: what is this called??)

Something that doesn't contain any whitespace (I am sure there is a better synonym for it, but I haven't figured out that yet)

**Examples:**

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

### Reading a string word

You can read into a variable that has the  `string` type using the `>>` operator. 

```c++
// read one word from cin
string s;
cin >> s;
```

input | value of s | location of the virtual cursor | explanation
--- | --- | --- | ---
"  apple  " | "apple" | "  apple▶️  " | Will skip whitespace **BEFORE** the word
"123" | "123" | "123▶️" | "123" is not the number 123 here. It is a vector with three characters (stores as text and not as number).
"apple123.      tree" | "apple123.," | "apple123.,▶️ tree" | Reads until the first whitespace
" apple tree" | "apple" | " apple▶️ tree" | Still stops at the first whitespace

### Reading a whole line

Because the `>>` operator stops at the first whitespace, we can't use that to read a while line, just one word.

But we can use the `getline` function.

```c++
string s;
getline(cin, s);
```

**remember: `'\n'` (the new line character) will be printed as a new line**

input | value of s | location of the virtual cursor | explanation
--- | --- | --- | ---
"  apple  \n" | "  apple  " | "  apple  \n▶️" | It will not save the newline character.
"line1\nline2" | "line1" | "line1\n▶️line2" | It will place the cursor to the start of the next line.
"word1 word2 word3\nword4" | "word1 word2 word3" | "word1 word2 word3\n▶️word4" | It will stop ONLY at the newline character.

# Reading data

Sometimes you don't need to store the data.

In this case just delete these lines:

* Definition of the vector `vector<T> v;`
* pushing to the vector `v.push_back(x);`
  * You can write your code here, at it's location

### Reading n floats from the console

The first line contains the number n = number of lines of data

```c++
// Known/fixed length
int n; // Stores / will store how many lines of data we should read
cin >> n;
vector<int> v; // I recommend ALWAYS using C++ vectors over C arrays
for (size_t i = 0; i < n; i++)
{
  // Currently v can't store any more items (i > v.size() - 1 <- the last valid index).
  // so we can't just write into it's next index (=i)
  // because we haven't reserved that memory yet.
  // So we will create a variable first and read into that.
  float x;
  cin >> x;
  // Then as a seperate task
  // we will append this x into the end of the array
  v.push_back(x);
}
```

#### The following code snippet will not work

```c++
vector<float> v;
cin >> v;
```

It might sound logical to read an element from the console into an vector,
but c++ doesn't allow this.

Instead we first need to read into a variable and then we can push the value of that value to the end of the vector.


### Reading n float from a file

```c++
ifstream f("data.txt");
if (f.good())
{
    // Known/fixed length
    int n;
    f >> n;
    vector<int> v;
    for (size_t i = 0; i < n; i++)
    {
        float x;
        f >> x;
        v.push_back(x);
    }
    file.close(); // Don't forget to close the file
    return 0;
}
else
{
    cerr << "Could not open the file" << endl;
    return 1;
}
```

### Reading until the end of the file

Usually the data doesn't contains 


