int maxStep(int arr[], int len)
{
    int count = 0;
    int maximum = 0;

    for (int index = 1; index < len; index++)
    {
        // count the number of consecutive
        // increasing height building
        if (arr[index] > arr[index - 1])
            count++;
        else
        {
            maximum = max(maximum, count);
            count = 0;
        }
    }

    return max(maximum, count);
}