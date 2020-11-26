# sum all numbers in a vector

Imagine you are building a tower.

* you start with a tower that has 0 height
* then you put the first brick on it
* then the second
* ...
* then the last
* **after the last one**:
* the height of the tower = sum of the height of the bricks

```c++
int sum(const vector<int> &v)
{
    int sum_so_far = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        sum_so_far += v[i]; // add it's value to the sum
    }
    // at this point all the bricks are measured
    // (the for loop had the condition: while I saw as many (i) item as there are (v.size()))
    // so the tower contains all the bricks
    // so it's height (sum_so_far) = sum of the brick's heights (expected result)
    return sum_so_far;
}

// USAGE:
vector<int> v;
v.push(1);
v.push(2);
// ...
v.push(10);

sum(v) == 55
```
