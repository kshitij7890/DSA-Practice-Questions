/*

Given a binary sorted non-increasing array of 1s and 0s. You need to print the count of 1s in the binary array.

Example 1:

Input:
N = 8
arr[] = {1,1,1,1,1,0,0,0}
Output: 5
Explanation: Number of 1's in given binary array : 1 1 1 1 1 0 0 0 is 5.

Example 2:

Input:
N = 8
arr[] = {1,1,0,0,0,0,0,0}
Output: 2
Explanation: Number of 1's in given binary array : 1 1 0 0 0 0 0 0 is 2.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)

*/

int countOnes(int arr[], int n)
    {
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2; 
            if(arr[mid]==1) 
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(arr[mid]==1)
        return mid+1;
        else
        return mid;
        
    }