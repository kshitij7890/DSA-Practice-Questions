#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int middle(int A, int B, int C){
        int maxi = max({A,B,C});
        int mini = min({A,B,C});
        if(A!=maxi && A!=mini) return A;
        else if(B!=maxi && B!=mini) return B;
        else if(C!=maxi && C!=mini) return C;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
} 