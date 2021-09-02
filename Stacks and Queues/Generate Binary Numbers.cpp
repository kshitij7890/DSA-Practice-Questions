/*

Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:

Input:
N = 2
Output: 
1 10
Explanation: 
Binary numbers from
1 to 2 are 1 and 10.

Example 2:

Input:
N = 5
Output: 
1 10 11 100 101
Explanation: 
Binary numbers from
1 to 5 are 1 , 10 , 11 , 100 and 101.

Expected Time Complexity : O(N log2N)
Expected Auxilliary Space : O(N log2N)

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int N)
{
    queue<string> q;
    vector<string> vec;
    q.push("1");
    for (int i = 0; i < N; i++)
    {
        vec.push_back(q.front());
        string x = q.front();
        q.pop();
        q.push(x + "0");
        q.push(x + "1");
    }
    return vec;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

/*

ALGO

1) Create an empty queue of strings 
2) Enqueue the first binary number "1" to queue. 
3) Now run a loop for generating and printing n binary numbers. 
......a) Dequeue and Print the front of queue. 
......b) Append "0" at the end of front item and enqueue it. 
......c) Append "1" at the end of front item and enqueue it.

*/