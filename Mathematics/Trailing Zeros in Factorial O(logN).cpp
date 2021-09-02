// Trailing zeroes in factorial 
// TC : O(logN)

#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    int trailingZeroes(int N)
    {
        int res=0;
        
        for(int i=5;i<=N;i=i*5)
        res=res+N/i;
        
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}