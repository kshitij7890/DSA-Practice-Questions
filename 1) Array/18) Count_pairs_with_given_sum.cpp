class Solution{   
public:

//TC : O(N)
//AS : O(N)

/*  

1) Create a map to store frequency of each number in the array. (Single traversal is required)
2) In the next traversal, for every element check if it can be combined with any other element 
   (other than itself!) to give the desired sum. Increment the counter accordingly.
3) After completion of second traversal, we’d have twice the required value stored in counter 
   because every pair is counted two times. Hence divide count by 2 and return.
*/

int getPairsCount(int arr[], int n, int k) 
{
    unordered_map<int,int>um;
        
    for(int i=0;i<n;i++)
    {
         um[arr[i]]++;
    }
        
    int count=0;
        
    for(int i=0;i<n;i++)
    {
        count += um[k-arr[i]];
        if(k-arr[i]==arr[i])
        {
            count--;
        }
    }
    
    return count/2;
}


};