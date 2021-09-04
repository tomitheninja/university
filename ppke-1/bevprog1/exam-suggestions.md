# Suggestions for the exam

## --> use a search engine <-- (while you study)

![](https://github.com/tomitheninja/university/blob/master/szemeszter-1/bevprog1/stackoverflow.jpg)

use google or duckduckgo. use them more than often. Even more often than that.

You are not the first to solve these problems.
There are already tens or hundreds of well-documented solutions out there.
You just need to find them.

Sadly only cppreference.com is allowed during the exam

## --> Learn logic and not ~code~ <--

We used to have programming exams in high school
where the solutions had to be exactly the same what the teacher presented to us.

Trust me you can't learn programming by memorizing the code.

The ones who tried hardest to get good marks on these tests are the ones who had trouble writing their own code later on.

You are not programming to write code anyway. You are programming to solve problems using the computer.
Code is just a tool for that. Code that doesn't solve any problem is as useless as a key that doesn't open anything.

### 1. practice

If you already figured out how to solve a task in the past, even if you might not remember how the code looked like, you do remember the logic behind it.

So re-creating a solution will be much easier and faster.

### 2. Set up a developer environment

#### 2.1. Learn how to use the debugger

[in 11 minutes](https://www.youtube.com/watch?v=MVXkcq6brZU)

It's very hard to find the bugs in your code by only seeing the input and the output.

Your chances to find a bug without using the debugger during the exam is very low.

But no worries, via the debugger you can run your program in small steps to locate the bug.

**extra**

If you want to print out a debugging message to the console like `RUNS UNTIL HERE` or `x = `

use the _console error stream_.

Because1: This way you can find your debugging statements easily if you want to remove them.

Because2: When an error checking robot or a linux user runs your program he can easily hide these messages.

```diff
- cout << "HERE" << endl;
+ cerr << "HERE" << endl;
```

#### 2.2. Try an other IDE / editor

[qt editor for open source](https://www.qt.io/download-open-source) and [vscode](https://code.visualstudio.com/docs/languages/cpp) has good support for c++, but they are harder to set up than code blocks.

But you only need to configure them once, so it might still worth it for you.

#### 2.3. Download a code analyzer

If your code produces random results or is crashing with "segmentation fault" then you are probably using "garbage memory" (RAM not assigned to your program)

This can happen when you are using an index outside an array's range or when using a reference to a variable that doesn't live/exists anymore (for example when it was declared inside a function that we returned from)

Many of these bugs can be caught with a static analyzer like [c++ check](http://cppcheck.sourceforge.net/#download) which even has a graphical interface.

Just press new project, open a folder and it will show **POTENTIAL** bugs.

-> It might also provide additional suggestions

but I think if your code runs fine, the exam is not the time to try things out.

### 3. Create checkpoints

The development process is not linear. It has ups and downs.

Make full backups via ctrl+c or git or comment out your old code.

But don't delete code **until you solved the problem**.

Who knows, you might need it later.
