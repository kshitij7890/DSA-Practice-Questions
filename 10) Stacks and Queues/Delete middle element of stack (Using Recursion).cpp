#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void deleteMid_util(stack<int>&s, int sizeOfStack, int current)
    {
        // check if current is half of the stack size, then you are at mid of stack
        if(current==sizeOfStack/2)
        {
            s.pop();
            return;
        }
        int x = s.top();
        s.pop();
        current+=1;

        // recursively call deleteMid funciton
        deleteMid_util(s,sizeOfStack,current);
        s.push(x);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        deleteMid_util(s,sizeOfStack,0);
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