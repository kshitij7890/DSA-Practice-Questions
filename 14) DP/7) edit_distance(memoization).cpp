//TC : O(N^2)
//AS : O(N^2)
#include<bits/stdc++.h>
using namespace std;

class Solution
{   int memo[102][102];
    int ed(string s,string t,int m,int n)
	    {    
	        if(memo[m][n]!=-1) return memo[m][n];
	        
	        if(m==0) return n;
	        if(n==0) return m;
	        
	        
	        if(s[m-1]==t[n-1]) 
	        memo[m][n]=ed(s,t,m-1,n-1);
	        else
	        memo[m][n]= 1+ min({ed(s,t,m-1,n-1),ed(s,t,m,n-1),ed(s,t,m-1,n)});
	        
	        
	        return memo[m][n];
	    }
	    
	public:
	    
		int editDistance(string s, string t)
		{
		   // memset(memo, -1, sizeof(memo));
		    int m=s.size();
		    int n=t.size();
		    for(int i=0;i<=m;i++)
		    {
		        for(int j=0;j<=n;j++)
		        {
		            memo[i][j]=-1;
		        }
		    }
		    int ans=ed(s,t,m,n);
		    return ans;
		}
		
		
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}