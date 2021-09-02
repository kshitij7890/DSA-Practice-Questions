/*

Smallest Positive missing number (Approach 1) -- By Rachit Jain Youtube Channel
TC : O(N)
AS : O(1)

APPROACH : 
We try to place 1 at index ( 1-1 ) , 2 at index (2-1) , 3 at index (3-1) , and so on.... and at last we traverse again 
and check where arr[i] != i+1 , that is our answer !!

How do we do that ?
We use a while loop inside for loop , and keep swapping the element arr[i] with arr[arr[i]-1] if arr[i]>=1 && arr[i]<=n

Although nested loops are used , It has linear time complexity as swapping of each element is done once 

*/

int missingNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        while (arr[i] <= n && arr[i] >= 1 && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[arr[i] - 1], arr[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
            
    return n + 1;
    
}