#include <bits/stdc++.h>
using namespace std;

long long maximumAmount(int arr[], int n) 
{
    int dp[n][n];
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1]=max(arr[i],arr[i+1]);
    }
    
    for(int gap=3;gap<n;gap+=2)
    {
        for(int i=0;gap+i<n;i++)
        {
            int j=gap+i;
            dp[i][j]=max(
                          arr[i] + min( 
                                        dp[i+2][j] , 
                                        dp[i+1][j-1] 
                                      ),
                                      
                          arr[j] + min( 
                                        dp[i][j-2] , 
                                        dp[i+1][j-1] 
                                      )
                        );
                        
        }
    }
    return dp[0][n-1];
}

int main() {
    
	int T;
	cin>>T;
	while(T--)

	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  