//TC : O(n)
//AS : O(1)

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