#include <bits/stdc++.h>
using namespace std;

//WORK ON BELOW TEST CASE FOR CLARITY
// arr[] : {20,8,27,37,9,12,46}
// o/p : 130

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int msis[n];
	    for(int i=0;i<n;i++)
	    {
	        msis[i]=arr[i]; 
	        // in LIS --> lis[i]=1;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                msis[i]=max(msis[i],msis[j]+arr[i]);
	                // in LIS --> lis[i]=max(lis[i],lis[j]+1);
	            }
	        }
	    }
	    
	    
	    
	    int res=msis[0];
	    for(int i=0;i<n;i++)
	    {
	        res=max(res,msis[i]);
	    }
	    return res;
	}  
};

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}