# Let's create a copy of our vector

Please take a look on both solutions and try to understand how returning and outputputing through a parameter compares.

I am quite sure you will face this problem on the exam

```c++
// returns a copy of v
vector<int> copy(const vector<int> &v)
{
  vector<int> v2;
  // note: v2.size() == 0, here
  for (size_t i = 0; i < v1.size(); i++)
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

## Same but with v2 as param
```c++
// copies v1 into v2
void copy(const vector<int> &v1, vector<int> &v2)
{
  // note: v2.size() == 0, here
  for (size_t i = 0; i < v1.size(); i++)
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

### Hacky solution

If you still remember pass by value makes a copy of the array.

But the teacher might not be happy about this solution

```c++
vector<int> copy(vector<int> v) // <- pass by value. Because we do want a copy of it
{
  return v;
}
```
