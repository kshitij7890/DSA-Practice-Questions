/* 

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

Expected TIme Complexity : O(n)
Expected Auxilliary Space : O(n)

In this Question we used 1 extra Stack for reversal and 1 extra Queue to maintain order of left out elements

*/

#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    queue<int> q1;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        q1.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while (!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
    }
    return q;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
