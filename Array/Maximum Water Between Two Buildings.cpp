/*

Given an integer array representing the heights of N buildings, the task is to delete N-2 buildings such that the water that can be 
trapped between the remaining two building is maximum.
Note: The total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of the smaller building.

Example 1:

Input: N = 6
height[] = {2,1,3,4,6,5}
Output: 8

Example 2:

Input: N = 2
height[] = {2,1}
Output: 0

*/

int maxWater(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    int res = 0;

    while (i <= j)
    {
        if (arr[i] < arr[j])
        {
            res = max(res, arr[i] * (j - i - 1));
            i++;
        }
        else
        {
            res = max(res, arr[j] * (j - i - 1));
            j--;
        }
    }

    return res;
}

/*

Two pointer approach : 

Take two pointers i and j pointing to the first and the last building respectively and calculate the water that can be stored between these two buildings. 
Now increment i if height[i] < height[j] else decrement j. This is because the water that can be trapped is dependent on the height of the small building 
and moving from the greater height building will just reduce the amount of water instead of maximizing it. 
In the end, print the maximum amount of water calculated so far.

*/