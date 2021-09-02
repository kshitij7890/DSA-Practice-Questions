
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
