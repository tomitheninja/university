# Find a value in the vector

Implementing this algorithm on **numbers** isn't that common

You might misinterpreted the task and need to use an other algorithm.

But if you need it, here it is:

### hard coded condition
```c++
// Finds a value greater than 5
// If found set's the result parameter to the number and returns true
// If not found returns false
bool find_val(const vector<int> &v, int &result)
{
  for (size_t i = 0; i < v.size(); i++)
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
bool find_val(const vector<int> &v, int &result, int min)
{
  for (size_t i = 0; i < v.size(); i++)
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
