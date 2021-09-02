#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,flag=0;
	    cin>>n>>x;
	    vector<int>arr(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==x)
	        {
	            cout<<i<<" ";
	            flag=1;
	            break;
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--)
	    {
	         if(arr[i]==x)
	        {
	            cout<<i<<" ";
	            flag=1;
	            break;
	        }
	    }
	    
	    if(flag==0)cout<<"-1"<<" ";
	    cout<<endl;
	    
	    
	}
	return 0;
}