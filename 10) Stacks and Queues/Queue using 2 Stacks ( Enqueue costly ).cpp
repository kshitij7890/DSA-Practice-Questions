/*

Method 1 (By making enQueue operation costly) 
This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1. 
To put the element at top of stack1, stack2 is used.

1) enQueue(q, x):
   a) While stack1 is not empty, push everything from stack1 to stack2.
   b) Push x to stack1 (assuming size of stacks is unlimited).
   c) Push everything back to stack1.
Here time complexity will be O(n)

2) deQueue(q):
   a) If stack1 is empty then error
   b) Pop an item from stack1 and return it
Here time complexity will be O(1)

*/

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty())
        {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

// Driver code
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}

/*

Complexity Analysis:

Time Complexity:
Push operation: O(N).
In the worst case we have empty whole of stack 1 into stack 2.
Pop operation: O(1).
Same as pop operation in stack.

Auxiliary Space: O(N).
Use of stack for storing values.

*/