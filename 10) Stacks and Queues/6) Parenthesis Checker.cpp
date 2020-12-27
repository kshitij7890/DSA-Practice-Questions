// PARENTHESIS CHECKER
// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

#include <bits/stdc++.h>
using namespace std;

bool matching(char c, char d)
{
    if ((c == '}' && d == '{') || (c == ']' && d == '[') || (c == ')' && d == '('))
        return true;
    else
        return false;
}
bool ispar(string x)
{
    stack<int> s;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '{' || x[i] == '[' || x[i] == '(')
        {
            s.push(x[i]);
        }
        else
        {
            if (s.empty() == true)
                return false;
            else if (matching(x[i], s.top()) == false)
                return false;
            else
                s.pop();
        }
    }
    return (s.empty());
}

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}