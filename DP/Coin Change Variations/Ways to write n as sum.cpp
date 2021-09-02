// Ways to write n as sum
// Same as Coin Change Problem

#include<bits/stdc++.h>
using namespace std;

int countWays(int);

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}

int countWays(int n)
{
    vector<long long int>arr;
    for(int i=1;i<n;i++)
    arr.push_back(i);
    
    int mod = (int)(1e9+7);
    
    long long int dp[n+1]={0};
    dp[0]=1;
    
    for(auto x:arr)
    {
        for(int i=1;i<=n;i++)
        {
            if(i>=x)
                dp[i]=((dp[i]%mod)+(dp[i-x]%mod))%mod;
        }
    }
    return dp[n]%mod;
}