# The most common algorithms implemented on int vector-s

! If you want to use these algorithms on real numbers (float, double) you will need to change the code at multiple locations

```fix
real number math and comparision is "buggy".
eg.: 0.1 + 0.2 == 0.30000000000000004
so when comparing real numbers always use an epsilon error margin like:
// eps := 0.01
// got result := 0.30000000000000004
// expected result := 0.3
abs(expected result - got result) < eps

-> if their difference is really small then they are equal
```

* [sum](./sum.md) összegzés tétele
* [count](./count.md) megszámlálás tétele
* [any / some](./any.md) eldöntés tétele
* [find index](./find_idx.md) kiválasztás tétele
* [find value](./find_val.md) keresés tétele
* [copy](./copy.md) másolás tétele
* [filter](./filter.md) kiválogatás tétele
* [smallest / largest](./min_max.md) szélsőérték keresés
* [index of smallest / largest](./min_max_idx.md) szélsőérték indexének keresése (ez inkább struct-oknál hasznos)
* [bubble sort](./bubble_sort.md) buborék rendezés
* [reverse](./reverse.md) tükrözés

# One liners

### required additional headers:

```c++
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
```
### The vector

```
vector<int> v;
v.push(42);
v.push(43);
// ...
```

### sum

```c++
// 0 is the initial value
int sum = accumulate(v.begin(), v.end(), 0);
```

### product

accumulate defaults to addition. We need to teach c++ how to do multiplication.

```c++
int multi(int a, int b) {
  return a * b;
}

int pro = accumulate(v.begin(), v.end(), 1, multi)
```

**with lambda expression**

```c++
int pro = accumulate(v.begin(), v.end(), 1, [](int a, int b){return a * b;})
```

### Find value

```c++
int find_this = -8;
auto result = find_if(v.begin(), v.end(), [&](int x) { return x == find_this; });

if (result != v.end()) // Reaching v.end() means not found
{
  cout << "Found " << *result << endl;
}
else
{
  cout << "Not found" << endl;
}
```

### Find index

```c++
auto result = find_if(v.begin(), v.end(), [](int x) { return x == 4; });

if (result != v.end())
{
  int i = distance(v.begin(), result);
  cout << "Found at " << i << endl;
}
else
{
  cout << "Not found" << endl;
}
```

### filter (keep the good bricks)

* back_inserter call's .push_back(x) on v2

```c++
vector<int> v2;
copy_if(
        v.begin(), v.end(), std::back_inserter(v2), [](int x) { return x > 10; });
```

### max / largest

Warning: will segfault when called on an empty vector.

```c++
int max = *max_element(v.begin(), v.end());
```


### min / smallest

Warning: will segfault when called on an empty vector.

```c++
int max = *min_element(v.begin(), v.end());
```

### sort

```c++
sort(v.begin(), v.end());
```

### reverse

```c++
reverse(v.begin(), v.end());
```
