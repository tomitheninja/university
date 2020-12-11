# Transform a string to UPPERCASE

```c++
string toupper(string s) {
    for (int i = 0; i < s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z') {
            s[i] += 'A' - 'a';
        }
    }
    return s;
}
```

# Transform a string to lowercase

```c++
string toupper(string s) {
    for (int i = 0; i < s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z') {
            s[i] -= 'A' - 'a';
        }
    }
    return s;
}
```
