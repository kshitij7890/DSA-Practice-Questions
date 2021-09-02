#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int res=arr[0];
    int currmax=arr[0];
    for(int i=1;i<n;i++)
    {   
        currmax = max(currmax+arr[i],arr[i]);
        res=max(res,currmax);
    }
    return res;
}

int main()
{
    int t,n;
    
    cin>>t; 
    while(t--) 
    {
        cin>>n; 
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; 
        cout << maxSubarraySum(a, n) << endl;
    }
}