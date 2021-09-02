//TC : O(N)
//AS : O(N)
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}

bool subArrayExists(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        arr[i]+=arr[i-1];
    }
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
       if(s.find(arr[i])!=s.end() || arr[i]==0)
       { 
          return true;  
       }
       s.insert(arr[i]);
    }
    return false;
}