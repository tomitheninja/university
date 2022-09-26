# Filter out the bad bricks

Let's throw out all the small bricks. No one needs them anyway.

To solve this problem, we actually need to think reverse and filter out the good bricks
(because we always wanted them, even tho the task didn't mention it)

throwing out the bad bricks = keeping the good bricks

### Filter out the good bricks

hint: just a copy algorithm with an extra condition.

* check every brick (the for loop)
* if we find a good brick (the if)
  * move it to the result set (push) // it's more like a copy because we don't change the original set
* take the new set as the result (return)

```c++
vector<int> filter(vector<int> v)
{
    vector<int> result;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 5)
        {
            // Found a good brick, let's copy it to the result set
            result.push_back(v[i]);
        }
    }
    return result;
}
```
