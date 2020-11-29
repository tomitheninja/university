# Suggestions for the exam

## --> use a search engine <-- (while you study)

![](./stackoverflow.jpg)

use google or duckduckgo. use them more than often. Even more often than that.

You are not the first to solve these problems.
There are already tens or hundreds of well documented solutions out there.
You just need to find them.

Sadly only cppreference.com is allowed during the exam

## --> Learn logic and not ~code~ <--

We used to have programming exams in high school
where the solutions had to be exactly the match what the teacher presented to us.

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

#### 2.2. Try an other IDE / editor

[qt editor for open source](https://www.qt.io/download-open-source) and [vscode](https://code.visualstudio.com/docs/languages/cpp) has good support for c++, but they are harder to set up than codeblocks.

But you only need to configure them once, so it might still worth it for you.

#### 2.3. Download a code analyzer

If your code produces random results or is crashing with "segmentation faults", then you are probably using "garbage memory" (an other program's RAM).

This can happen when using an index outside an array's range or when using a reference to a variable that doesn't live anymore (was declared inside a function for example)

Many of these bugs can be caught with a static analyzer like [c++ check](http://cppcheck.sourceforge.net/#download) which even have a nice graphical interface.

Just press new project, open a folder and it will show **POTENTIONAL** bugs.

-> It might also provide additional suggestions

but I think if your code runs fine, the exam is not the time to try things out.

### 3. Create checkpoints

The development process is not linear. It has up's and down's.

Make full backups via ctrl+c or git or comment out your old code.

But don't delete code **until you solved the problem**.

Who knowns, you might need it later.
