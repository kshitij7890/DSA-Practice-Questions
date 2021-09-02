/*

Method 2 (By making deQueue operation costly)
In this method, in en-queue operation, the new element is entered at the top of stack1. 
In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)


Method 2 is definitely better than method 1.
Method 1 moves all the elements twice in enQueue operation, while method 2 (in deQueue operation) moves the elements once and moves elements only if stack2 empty. 
So, the amortized complexity of the dequeue operation becomes  /Theta (1) .

*/

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack
        s1.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty())
        {
            cout << "Q is empty";
            exit(0);
        }

        // if s2 is empty, move
        // elements from s1
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // return the top item from s2
        int x = s2.top();
        s2.pop();
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
Push operation: O(1).
Same as pop operation in stack.
Pop operation: O(N).
In the worst case we have empty whole of stack 1 into stack 2

Auxiliary Space: O(N).
Use of stack for storing values.

*/