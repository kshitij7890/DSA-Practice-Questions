/*
----------------------------------------------------------------------------------------------------------------------------------------------------------
Now, we'll try to solve a famous stack problem.
You are given an array A of size N. You need to first push the elements of the array into a stack and then print minimum in the stack at each pop.
---------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 5
A = {1 2 3 4 5}
Output: 
1 1 1 1 1
Explanation: 
After pushing elements to the stack, 
the stack will be "top -> 5, 4, 3, 2, 1". 
Now, start popping elements from the stack
popping 5: min in the stack is 1.popped 5
popping 4: min in the stack is 1. popped 4
popping 3: min in the stack is 1. popped 3
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
----------------------------------------------------------------------------------------------------------------------------------------------------------
Example 2:

Input: 
N = 7
A = {1 6 43 1 2 0 5}
Output: 
0 0 1 1 1 1 1
Explanation: 
After pushing the elements to the stack, 
the stack will be 5->0->2->1->43->6->1. 
Now, poping the elements from the stack:
popping 5: min in the stack is 0. popped 5
popping 0: min in the stack is 0. popped 0
popping 2: min in the stack is 1. popped 2
popping 1: min in the stack is 1. popped 1
popping 43: min in the stack is 1. 
            popped 43
popping 6: min in the stack is 1. popped 6
popping 1: min in the stack is 1. popped 1.
----------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[], int n);
void _getMinAtPop(stack<int> s);
//----------------------------------------------------------------------------------------------------------------------------------------------------------
stack<int> _push(int arr[], int n)
{
    stack<int> s;

    // iterating over the array elements and pushing into the stack
    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
    }
    return s;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
void _getMinAtPop(stack<int> s)
{
    std::vector<int> v;

    // while there is element in stack
    while (!s.empty())
    {
        // push the top element into the vector
        v.push_back(s.top());

        // pop the elment from stack
        s.pop();
    }

    stack<int> minStack;

    s.push(v.back());

    // pushing last element as min element
    minStack.push(v.back());

    // iterating vector from second last
    for (int i = v.size() - 2; i >= 0; i--)
    {
        s.push(v[i]);

        // compare the top element with minStack top
        // and then push the element if required
        if (s.top() < minStack.top())
            minStack.push(s.top());
        else
            minStack.push(minStack.top());
    }

    // print the minimum at every pop
    while (!s.empty())
    {
        cout << minStack.top() << " ";
        s.pop();
        minStack.pop();
    }
    cout << endl;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        stack<int> mys = _push(arr, n);
        _getMinAtPop(mys);
    }
    return 0;
}
