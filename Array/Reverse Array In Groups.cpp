class Solution{
public:
    void rA(vector<long long>& arr, int start, int end)
    {
        while (start < end)
        {
           int temp = arr[start]; 
           arr[start] = arr[end];
           arr[end] = temp;
           start++;
           end--;
        } 
    }  
    
    void reverseInGroups(vector<long long>& arr, int n, int k)
    {
        
        for(int i=0;i<n;i+=k)
        {
          int left=i;
          int right=min(i+k-1,n-1);
          rA(arr,left,right);
        }
        
    }
};