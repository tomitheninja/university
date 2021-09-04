# Find the largest brick (max element of brick sizes)

Let's assume we have at least one brick. (There is no largest element in the empty set)

Let's put all our bricks in a linear path (in a vector).

Pick up the first and compare it to the second.

Keep the larger (drop the one in our hand if the other is larger and pick that up)

compare the larger to the third.

Again keep the larger and compare it to the next one.

...

After comparing the brick in our hand with the last one,

keep the larger. That's the largest of all the bricks.

```c++
// Find the largest number in the vector
int find_largest(vector<int> v)
{
    int largest_so_far = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        // (current: v[i]) vs (best: largest_so_far)
        if (v[i] > largest_so_far)
        {
            // found a larger
            // replace the one in our hand
            largest_so_far = v[i];
        }
    }
    // at this point largest_so_far holds the largest item
    return largest_so_far;
}
```

### The smallest

replace the condition in the if statement and rename the variable
```diff
- if (v[i] > largest_so_far)
+ if (v[i] < smallest_so_far)
```
