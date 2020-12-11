# Bubble sort

The basic idea:

* Sorts the array by pushing the largest element to the end of the array (size - 1)

* Then pushes the second largest element to the (size - 2) location

* ...

* Until there is nothing left to sort (only 1 item can't be unsorted)

* at this point the array is sorted

## Short version

It's unlikely that you will ever write your own sorting algorithm IRL, but
you are not allowed to use pre-written code (like `std::sort(arr)`) during the exam

So you need to memorize the following snippet:

```c++
void sort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < v.size() - i; j++)
        {
            int tmp = v[j - 1];
            v[j - 1] = v[0];
            v[j - 1] = tmp;
        }
    }
}
```

## Explained version

```c++
// sort people by their name
// algorithm: bubble sort
// visualization: https://is.gd/QRbE09
void sort(vector<Person> &people)
{
    // divide the array into an ordered and an unordered part
    // by default every element is unordered
    for (int i = 0; i < people.size(); i++)
    {
        // in every iteration we place one item into its final position
        // (which is at the end of the array now)
        // hence decreasing the unordered part by one
        // and increasing the ordered part by one item

        // the variable i keeps track of the unsorted part's length

        // so this loop will only work on the unordered part
        for (int j = 1; j < people.size() - i; j++)
        {
            // pick two neighbors
            // p1 = people[j - 1]
            // p2 = people[j]
            // check: in wrong order? [a > b]
            if (people[j - 1].name > people[j].name)
            {
                // swap them -> (now this pair is in correct order [b < a])
                swap(people[j], people[j - 1]);

                // the std::swap is a built in function that works like this:
                // Person tmp = people[j];
                // people[j] = people[j - 1];
                // people[j - 1] = tmp;
            }
        }
        // At this point
        // the largest element of the unsorted part
        // is pushed onto the end of it.
        // So the last i+1 elements are sorted by now
    }
    // Repeat until there are no more unsorted elements
}
```
