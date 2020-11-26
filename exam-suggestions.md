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
where the solutions had to be exactly the same as the one in our teacher's presentation.

Trust me you can't learn programming by memorizing the code.

The ones who tried hardest to get good marks on these tests are the ones who had trouble when writing their own code later on.

You are not programming to write code anyway. You are programming to solve problems using the computer.
Code is just a tool for that. A key without the car is pretty useless.

We are only using computers, because they are very good at solving some problems.

You can calculate [bitcoin hashes on paper](http://www.righto.com/2014/09/mining-bitcoin-with-pencil-and-paper.html),
it just happens that a computer can do it a trillion times faster.

### 1. practice

If you already figured out how to solve a task in the past, even if you might not remember how the code looked like, you do remember the logic behind it.

So re-learning the solution will be much much easier and faster.

### 2. Set up a developer environment

#### 2.1. Learn how to use the debugger

[in 11 minutes](https://www.youtube.com/watch?v=MVXkcq6brZU)

It's very hard to find the bugs in your code by only seeing the input and the output.

But no worries, via the debugger you can run your program in small steps to locate the location of a bug.

Your chances to find a bug without the debugger during the exam is almost zero.

#### 2.2. Try an other IDE / editor

[qt editor for open source](https://www.qt.io/download-open-source) and [vscode](https://code.visualstudio.com/docs/languages/cpp) has good support for c++, but they are harder to set up than codeblocks.

But you only need to configure them once, so it can still worth it.

#### 2.3. Download a code analyzer

If your code produces random results or is segfault-ing, then you might using "garbage memory" (an other program's RAM)

Many of these bugs can be caught with a static analyzer like [c++ check](http://cppcheck.sourceforge.net/#download) which have a graphical interface.

Just press new project, open a folder and it will show **POTENTIONAL** bugs.

-> It might also provide additional suggestions

but I say if your code runs fine, the exam is not the time to try things out.

### 3. Create checkpoints

The development process is not linear. It has up's and down's.

Make full backups via ctrl+c or git or comment out your old code.

But don't delete any code **until you solved the problem**.

Who knowns, you might need it.
