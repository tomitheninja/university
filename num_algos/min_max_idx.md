# Index of the smallest element

This algorithm is mostly used with complex (struct) types

```fix
We are not searching for the smallest index (which is 0)

We are looking for the index of the smallest item in the vector
```


Almost identical to a regular min algorithm, but stores the index of an element not it's value.

That's not a problem because any value can be accessed through it's index. `val= v[idx]`

```c++
int min_idx(const vector<int> &v)
{
  int min_val_idx = 0;
  for (size_t i = 0; i < v.size(); i++)
  {
    if (v[i] < v[min_val_idx])
    {
      min_val_idx = i;
    }
  }
  return min_val_idx;
}
```
