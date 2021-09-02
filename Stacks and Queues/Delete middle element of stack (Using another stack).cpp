#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void deleteMid(stack<int>&s, int size)
    {
        stack<int>temp;
        for(int i=0;i<(size/2);i++)
        {
            int x=s.top();
            temp.push(x);
            s.pop();

        }
        
        s.pop();
        
        for(int i=0;i<(size/2);i++)
        {
            int y=temp.top();
            s.push(y);
            temp.pop();
        }
        
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}