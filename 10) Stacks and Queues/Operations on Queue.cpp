#include <bits/stdc++.h>
using namespace std;

// Function to push element on rear of queue
void enqueue(queue<int> &q,int x)
{
   q.push(x);
}
 // Function to remove front element from queue
void dequeue(queue<int> &q)
{
    if(!q.empty()) q.pop();
}
 // Function to find the front element of queue
int front(queue<int> &q)
{
    return q.front();
}
 // Function to find the element in queue. Return "Yes" or "No".
string find(queue<int> q, int x)
{
    while(!q.empty())
    {
        if(q.front()==x) return "Yes";
        q.pop();
    }
    return "No";
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    queue<int> s;
	    int q;
	    cin>>q;
	    while(q--){
	        char ch;
	        cin>>ch;
	        
	        if(ch=='i')
	        {
	            int x;
	            cin>>x;
	            
	            enqueue(s,x);
	            
	        }
	        else if(ch=='r')
	        {
	            dequeue(s);
	        }
	        else if(ch=='h')
	        {
	            cout << front(s) << endl;
	        }
	        else if(ch=='f')
	        {
	            int x;
	            cin>>x;
	            cout << find(s,x) << endl;
	        }
	        
	    }
	}
	return 0;
}