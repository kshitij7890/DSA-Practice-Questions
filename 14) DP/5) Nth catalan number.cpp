// Same as Unique BSTs Question

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

cpp_int findCatalan(int);

int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    
	    cout<< findCatalan(n) <<"\n";    
	}
	return 0;
}

cpp_int findCatalan(int n) {
    cpp_int dp[n+1];
    //int mod = 1000000007;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {   dp[i]=0;
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1]; 
            //if(dp[i]>=mod) dp[i]%=mod;
        }

    }
    return dp[n];
}
