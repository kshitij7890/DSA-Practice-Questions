/*

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. 
Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:
Input: S = "231*+9-"
Output: -4

Example 2:
Input: S = "123+*8-"
Output: -3

Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s)
{
    stack<int> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i])) //s[i] is from 0 to 9
        {
            stk.push(s[i] - '0');
        }
        else
        {
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();
            if (s[i] == '+')
                stk.push(op2 + op1);
            else if (s[i] == '-')
                stk.push(op2 - op1);
            else if (s[i] == '*')
                stk.push(op2 * op1);
            else if (s[i] == '/')
                stk.push(op2 / op1);
        }
    }
    return stk.top();
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;

        cout << evaluatePostfix(S) << endl;
    }
    return 0;
}