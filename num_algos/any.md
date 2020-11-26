# Is there any item with this property?

It's almost like the find algorithm, except

* instead of returning the item when found
* the function returns _true_
* and _false_ if not found

Because the answer to the "is there any" question is **yes/no** and not **"this one"**

### Task: Do we have any good bricks? 

```c++
// Check if any/some of the items in the vector matches a criteria
bool any(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v[i] >= 5)
        {
            return true; // found one
        }
    }
    // we checked all items, but not found any :(
    return false;
}
```

### Task: same, but with a parameter

```c++
// Check if any/some of the items in the vector matches a criteria
bool any(const vector<int> &v, int min_size)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v[i] >= min_size)
        {
            return true; // found one
        }
    }
    // we checked all items, but not found any :(
    return false;
}
```
