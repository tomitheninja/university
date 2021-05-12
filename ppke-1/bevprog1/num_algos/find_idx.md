# Find / Where is Waldo?

* Everyone know's how waldo looks like. [right?](https://www.wikihow.com/images/4/4b/Find-Waldo-Step-10.jpg)
* But only a few know where he is.

So we need the **location** of Waldo.

Usually, if we know where he is we can just go there and ask him any additional questions.
Just like with street addresses irl.

Algorithm:

* Let's check a person
  * If the person is Waldo -> return where he is and stop the search
  * If the person isn't Waldo -> let's check another person (which we haven't checked yet) 
* If we asked every single person, but didn't find him return an error code (-1)

```c++
// Returns the index of the item, if it found it
// returns -1 if not found
int find_index_of(vector<int> v, int item)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == item) // "Are you Waldo?"
        {
            // Yes? -> Hey, here he is!
            // this return will auto exit the function and return the index (location) of Waldo 
            return i; 
          
        }
    }
    // Waldo isn't here. 
    // index cant be negative so we can use -1 as an indicator
    // it's not a nice thing to do (antipattern),
    // but everybody does it this way
    return -1;
}
```
