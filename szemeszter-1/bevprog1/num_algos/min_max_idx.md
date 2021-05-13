# Index of the smallest element

This algorithm is mostly used with complex (struct) types

```fix
We are not searching for the smallest index (which is 0)

We are looking for the index of the smallest item in the vector
```


Almost identical to a regular min algorithm, but stores the index of an element not it's value.

That's not a problem because any value can be accessed through it's index. `val= v[idx]`

```c++
int min_idx(vector<int> v)
{
  int min_val_idx = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] < v[min_val_idx])
    {
      min_val_idx = i;
    }
  }
  return min_val_idx;
}
```

## In case you can't access the previous value

Cache the best value in a variable.

```c++
int legjobb_indexe = -1;
float legjobb_ertek = 0; // this is the cache
for (int i = 0; i < v.size(); i++)
{
    float mostani = v[i];
    if (mostani > legjobb_ertek)
    {
        legjobb_ertek = mostani;
        legjobb_indexe = i;
    }
}
return legjobb_indexe;
```
