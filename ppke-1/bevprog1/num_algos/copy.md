# Let's create a copy of our vector

Please take a look on both solutions and try to understand how returning and outputing through a parameter compares.

You will almost certainly have to use both on the exam if you have to complete some half-done code which is a common task.

```c++
// returns a copy of v
vector<int> copy(vector<int> v)
{
  vector<int> v2;
  // note: v2.size() == 0, here
  for (int i = 0; i < v1.size(); i++)
  {
    // so we can't use
    // v[i] = v2[i] here, because
    // v2 has a size of 0, which can't fit any items.
    //
    // so we need to expand v2
    // before we set it's last value.
    // Luckily c++ has a method to do these two tasks in one call:
    v2.push(v1[i]);
  }
  return v2;
}
```

#### Usage:
```c++

int result = returns_by_value(param1);

```

## Same but outputing the result through a reference

In some cases (like when you want to return multiple values), you can't use returning by value.

In this case, you have to create a (reference) parameter to each value you want to return.

```c++
// copies v1 into v2
// v2 is the output param
// so it must be a non-constant reference
void copy(vector<int> v1, vector<int> v2)
{
  // note: v2.size() == 0, here
  for (int i = 0; i < v1.size(); i++)
  {
    // so we can't use
    // v1[i] = v2[i] here, because
    // v2 has a size of 0, which can't fit any items.
    //
    // so we need to expand v2
    // before we set it's last value.
    // Luckily c++ has a method to do these two tasks in one call:
    v2.push(v1[i]);
  }
}
```

#### Usage

```c++
int result;
outputs_through_parameter(param1, result);
```
