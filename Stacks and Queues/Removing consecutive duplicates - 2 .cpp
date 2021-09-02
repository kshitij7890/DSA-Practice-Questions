/*

You are given string str. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together. 

Example 1:

Input: aaabbaaccd
Output: ad

Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad

Example 2:

Input: aaaa
Output: Empty String

*/

#include <bits/stdc++.h>
using namespace std;

string removePair(string str)
{
    string vec = "";
    stack<char> s;
    s.push(str[str.length() - 1]);
    for (int i = str.length() - 2; i >= 0; i--)
    {
        if (s.empty() == true)
            s.push(str[i]);
        else if (str[i] == s.top())
            s.pop();
        else
            s.push(str[i]);
    }

    while (!s.empty())
    {
        char c = s.top();
        s.pop();
        vec.push_back(c);
    }
    return vec;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        string ans = removePair(s);

        if (ans == "")
            cout << "Empty String" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}