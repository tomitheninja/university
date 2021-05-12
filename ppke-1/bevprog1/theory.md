# Theory/notes

always prefer the definition of the teacher's presentation
over these as they might not be 100% accurate.

## Compilation

the process that converts the c++ source code into instructions that the computer can understand.

(ones and zeros)

## Variable

A storage that can hold a value with a given type.

Imagine you are calculating on paper.
You can write down results and partial results somewhere on the paper and when it changes, you cross out the old value and write down the new one next to it. This is almost how variables work.

## Definition / declaration

creating a new variable with a known type.

```c++
int x;
```

## Assignment

Change the value of a variable (assign a new value to the variable)

```c++
x = 123
// or
x = y // y is an ther
```

## Initialization

Setting an **initial value** right where/when the variable is declared

```c++
int x = 123;
// sometimes not the same as:
int x;
x = 123;
```

## Constant

const in programming usually means that
the "variable" can't be changed after initialization.

However, in c++ and many other languages, it does not mean, that
the variable has a known value at compilation time.

For example, the following code is valid:
```c++
int a;
cin >> a;
const int x = a; // x has unknown value, but that's not the point.
// what matters is that you can't change the value of x anymore after its initialization.


 x = 123; // this will result in an compilation error, because 
// x is const so you can't change it's value
```

## Parameter

The variable you define in the function's header.

```c++
int f(int param1, int param2)
{
  // ...
}
```

## Arguments

The value you call the function with.

```c++
f(argument1, argument2);
```

## Pass by value [copy]
```int f(int x) {}``` <-- **can't change the value of x outside the function**

When calling the function f(x), c++ will make a copy of x and pass that copy to the function.

It means no matter what you do with the argument inside the function,
since it's only a copy of the original value, it will not modify the original value.

So if you change the value inside the function, the outside value will **NOT** change.

_This is the most common case when passing **primitives** (like numbers, characters, ... <- cause they have fixed size)_

```fix
! isteam doesn't support passing by value

But as I'll write down soon, struct's shouldn't be passed by value (in most cases).
```

## Pass by reference [can change outside]

```void repair(Car &c) {}``` <-- **can change the car (c param)**

If indicated with the & symbol, the compiler (instead of copying the value), will create a virtual arrow (a reference) to the original value.

Then copies this reference (so it will still point to the original value)

then automatically dereferences the arrow for you, so you will have direct **access to the original** value.

If you change the value inside the function, the outside value will ALSO change.

_This is the only way (at least what I know) you can use to **change a value** outside the function_

## you don't need this -> ~~Pass by const reference [can't change outside]~~

**Update: Performance doesn't matter on the exam. Feel free to use pass by value (copy) instead of this.**

```int sum(const vector<int> &v) {}``` <-- **like pass by value but faster for complex types**

Same as passing by reference, but the compiler will disallow changing the value inside the function.

_This is the preferred method when passing **arrays** to function because making a copy of their original value might be expensive in case they are very large._

_Usually every **Struct** is passed like this, as they can also contain an array_

(if not now, someone might change the code later to do so).
