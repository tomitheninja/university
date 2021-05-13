# Average

#### Real number type

integers (like int) can't hold fractions.

So c++ will drop the fraction part when assiging a real number to an integer or making operations between integers.

real numbers (like float or double) does not have this problem but they can only hold an approximation of the number we want.

### Sum of integers

copy the sum function from [here](./sum.md)

Dividing integers by integers will also return integers, but we want to avg as a real number.

(because integers doesn't include the fraction)

So we need to convert any of our number's into a real number so the result will also include the fraction.

```c++
float avg(vector<int> v)
{
  return (float)sum(v) / v.size();
}

// USAGE:
vector<int> v;
v.push(1);
v.push(2);
avg(v) == 1.5
```

### Sum of real numbers

copy the sum function from [here](./sum.md) and replace the (int) type with whatever real number type you preffer (float or double)

Dividing a real number by any number will result in a real number.

So it works like expected.

```c++
float avg(vector<float> v)
{
  return sum_real(v) / v.size();
}

// USAGE:
vector<float> v;
v.push(1.2);
v.push(2);
avg(v) == 1.6
```
