# Do we have any item with the searched property?

It's almost like the find algorithm, except

* instead of returning the item when found
* the function returns _true_
* and _false_ if not found

that's because the answer to the "is there any" question is **yes** or **no** and instead of **"this one"**

### Task: Do we have any good bricks? 

```c++
// Check if any of the items in the vector matches a criteria
bool any(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] >= 5)
        {
            return true; // found one
            // The computer will exit from the function
            // when it meets a return instruction.
        }
    }
    // we checked all items, but not found any :(
    return false;
}
```

### Task: same, but with a parameter

```c++
// Check if any of the items in the vector matches a criteria
bool any(vector<int> v, int min_size)
{
    for (int i = 0; i < v.size(); ++i)
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
