# Is substring / contains / includes

Works simillary to string.find [cplusplus.com](https://www.cplusplus.com/reference/string/string/find/), but returns a bool instead of the starting index of the match

Let's check if s1 contains s2

Imagine you have two rulers

And you are moving one of them sideways until you find a positions where every common items match on them

If you found one, you can return true

If you checked all possible positions, but u didn't found any

That means the second ruler can't be a part of the first one

return false

## I recommend string.find != string::nops instead ~~Clean version~~

```c++
bool is_substring(string s1, string s2)
{
    for (int i = 0; i <= s1.size() - s2.size(); i++)
    {
        bool found = true;
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i + j] != s2[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return true;
        }
    }
    return false;
}
```

## Explained version

```c++
// returns true if s2 is a substring of s1
bool is_substring(string s1, string s2)
{
    // The latest position where s2 can start is
    // is s1.size() - s2.size()
    // anywhere right from there
    // s2 would span further than s1

    // please note that s1.size() can equal s2.size
    for (int i = 0; i <= s1.size() - s2.size(); i++)
    {
        // let's go indirect
        // suppose we found it,
        // if we can't find an exception
        bool found = true;

        // for every character in s2
        for (int j = 0; j < s2.size(); j++) // compare the subset of s1 with s2
        {
            // if they are the same
            // our assumption is still valid

            // But if they are different
            // Our assumption failed
            if (s1[i + j] != s2[j])
            {
                // Indicate that
                found = false;
                // Optimization:
                // We already know that they are different
                // we don't need to find another exceptions.

                // let's jump out from the loop.
                // the break statement exit's from the closest loop
                break;
            }
        }
        // We couldn't find an exception
        // that means we found it
        if (found)
        {
            return true;
        }
        // Let's try again with the next character of s1
    }
    // We tried every possible starting position of s2 in s1
    // We couldn't find any
    // otherwise return true would have quit from this function
    // return false, because we didn't find it
    return false;
}
```
