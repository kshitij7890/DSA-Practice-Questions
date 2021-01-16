/*
Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. 
If no character of patt is present in str then print ‘No character present’.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
str = geeksforgeeks
patt = set
Output: e
Explanation: e is the character which is
present in given patt "geeksforgeeks"
and is first found in str "set".
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int minIndexChar(string str, string patt)
{
    char ch[patt.length()];
    unordered_set<char> s;
    for (int i = 0; i < patt.length(); i++)
    {
        ch[i] = patt[i];
        s.insert(ch[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (s.find(str[i]) != s.end())
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string patt;
        cin >> str;
        cin >> patt;
        int ans = minIndexChar(str, patt);
        if (ans == -1)
            cout << "No character present";
        else
            cout << str[ans];
        cout << endl;
    }
    return 0;
}
