# Count how many items in the vector have a searched property

Imagine that we want to build a house and we have a lot of bricks, but some are too small to be used for the task.

let's count how many good bricks we have. Let's say a brick is good if its size is > 5

```diff
- you don't want to count all the bricks without any condition
- in english: ("how many bricks I have?")
- because that will always equal v.size()
```

also, all the bricks are in a nice linear path (in an array), so we don't have to worry about counting one multiple times (like we often do when counting the number of people in a group.

### TASK: Count how many bricks are larger than 5

* close all your fingers (count = 0)
* and start measuring all the bricks (for loop)
* if the brick is good, open up one finger (count += 1, or just count++)
* go to the next one until there are no more left (for loop)

```c++
int count_many(vector<int> v)
{
    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > 5) // min_size is hard coded here to be 5
        {
            count++;
        }
    }
}

// USAGE:
vector<int> v;
v.push_back(5);
v.push_back(12);
// ...
v.push_back(1);

int count_good = count_many(v);
return 0;
```

### TASK: Why 5? Why not 4? or 10!

we hardcoded 5 as the minimum size. What if another client says 10?

We don't want to make a new function for every possible situation, so let's make some changes to the function so it will work with any min_size.

```c++
int count_many(vector<int> v, int min_size)
{
    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > min_size)
        {
            count++;
        }
    }
}

// USAGE:
vector<int> v;
v.push_back(5);
v.push_back(12);
// ...
v.push_back(1);

int count_many_good = count_many(v, 10);
return 0;
```
