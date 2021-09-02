// Minimum number of deletions to make a sorted sequence
// LIS Variation
// TC : O(n^2)
// TC : O(n)

int minDeletions(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    int res = lis[0];
    for (int i = 0; i < n; i++)
    {
        res = max(res, lis[i]);
    }
    return n - res; // in LIS --> return res;
}