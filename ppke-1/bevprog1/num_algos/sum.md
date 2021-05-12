# sum all numbers in a vector

Summing all items in an array is a fairly abstract problem.

So instead let's measure the height of a very-very tall tower.

The problem is that our only tool is a simple ruler which can only measure one brick at a given type. (yes I am talking about you CPU)

Can we still measure the height of the tower?

Of course we can!

We will do it brick-by-brick then!

Here is our algorithm:

* The height of zero bricks is zero (tower_height = 0) 
* measure the first's bricks height and add this value to the total height (tower_height += first brick's height)
* then do the same with the next brick (tower_height += second brick's height)
* ...
* do the same with the last one (tower_height += last brick's height)
* **at this point**:
* sum of all the measured bricks height = the tower's height

We successfully measured the height of a very complex structure (the tower = the array)

by using only very simple operations (measuring on brick's height, summing two numbers).

```c++
int sum(vector<int> v)
{
    int sum_so_far = 0;
    for (int i = 0; i < v.size(); i++) // for each available index in v
    {
        sum_so_far += v[i]; // add the item's value to the sum
    }
    // at this point all the bricks are measured
    // so the sum of the height of the bricks (sum_so_far) = the tower's height
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

## One line solution

Don't forget to include all header files

```c++
vector<int> v;
for (int i = 1; i <= 10; i++)
{
    v.push_back(i);
}
// start with the 0 zero initialial value
// sum all items between v.begin() and v.end() 
int sum = accumulate(v.begin(), v.end(), 0);
cout << sum << endl;
return 0;
```

### Product

```c++
// we need a custom handler function
int multi(int a, int b)
{
    return a * b;
}

// Pass that custom function as the 4th argument
int pro = accumulate(v.begin(), v.end(), 1, multi);
cout << pro << endl;
return 0;
```
