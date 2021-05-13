# Reverse a vector

#### note

When swapping the first element with the last we don't just put the first into its correct location.

Swapping the two will also put the last elementpping the two will also put  into its correct location.

So we need to swap only half the vector

#### code

```c++
for (int i = 0; i < v.size() / 2; i++) {
    // start_idx := first index = 0
    // end_idx := last index = v.size() - 1
    // swap(v[start_idx + i], v[end_idx - i]);
    int tmp = arr[i];
    v[i] = v[v.size() - 1 - i];
    v[v.size() - 1 - i] = tmp;
}
```
