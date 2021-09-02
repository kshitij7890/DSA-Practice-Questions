//TC : O(n)
//AS : O(1)

/*

Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
Output : 4
Explanation: The frequency of 4 is 5 which is greater
than the half of the size of the array size. 

Input : {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element

*/

int majorityElement(int arr[], int n)
{
    int idx = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[idx])
        {
            count++;
        }
        else
            count--;

        if (count == 0)
        {
            count = 1;
            idx = i;
        }
    }

    int c = 0;
    int res = arr[idx];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[idx])
        {
            c++;
        }
    }
    if (c <= (n / 2))
        res = -1;
    return res;
}