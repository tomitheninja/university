# Find a value in the vector

Implementing this algorithm on **numbers** isn't that common

You might have misinterpreted the task and need to use another algorithm.

When using primitives (like numbers), we already have access to all their properties.

In this case the algorithm can be replaced with this following:

```c++
if (this item is in the vector) // any_equals(v, this item)
{
   // then do something with it
} else {
  // print an error or use a default value or idk
}
```

If you need to implement the find value algorithm for primitives (99.9% you are not), here it is:

### hard coded condition
```c++
// Finds a value greater than 5
// If found set's the result parameter to the number and returns true
// If not found returns false
bool find_val(vector<int> v, int &result)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] > 5) {
      result = v[i];
      return true;
    }
  }
  return false;
}

// USAGE:
vector<int> v;
v.push(10);
v.push(7);
// ...
int result;
if (find_val(v, result)) {
  cout << "Found << result << endl;
} else {
  cout << "Not found" << endl;
}
```

### condition depending on a parameter
```c++
// Finds a value greater than min
// If found set's the result parameter to the number and returns true
// If not found returns false
bool find_val(vector<int> v, int &result, int min)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] > min) {
      result = v[i];
      return true;
    }
  }
  return false;
}

// USAGE:
vector<int> v;
v.push(10);
v.push(7);
// ...
int result;
if (find_val(v, result, 10)) {
  cout << "Found << result << endl;
} else {
  cout << "Not found" << endl;
}
```
