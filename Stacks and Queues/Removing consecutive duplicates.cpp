/*

You are given string str. You need to remove the consecutive duplicates from the given string using a Stack.
 
Example 1:

Input: aaaaaabaabccccccc
Output: ababc
Explanation: 
Removing all consecutive duplicates, 
we have no duplicates consecutively.

*/


#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveDuplicates(string str)
{
    stack<char>s;
    s.push(str[str.length()-1]);
    string vec;
    for(int i=str.length()-2;i>=0;i--)
    {
        if(str[i]!=str[i+1])
        s.push(str[i]);
    }
    
    while(!s.empty())
    {
        char c=s.top();
        s.pop();
        vec.push_back(c);
    }
    return vec;
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        cout<<removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
} 