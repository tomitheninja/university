# Reverse a vector

note: When swapping the first with the last we don't just put the first into it's correct location.

Swapping the two will also put the last item into it's correct location.

So we need to swap only half the vector

```c++
for (size_t i = 0; i < v.size() / 2; i++) {
    // start := first index = 0
    // end := last index = v.size() - 1
    // swap(v[start + i], v[end - i]);
    int tmp = arr[i];
    v[i] = v[v.size() - 1 - i];
    v[v.size() - 1 - i] = tmp;
}
```
