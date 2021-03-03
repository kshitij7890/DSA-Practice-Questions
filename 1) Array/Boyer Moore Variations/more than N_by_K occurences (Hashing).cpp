// Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
// Hashmap Approach(not the best)

int countOccurence(int arr[], int n, int k)
{
    int x = n / k;
    unordered_map<int, int> um;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;
    }

    for (auto y : um)
        if (y.second > x)
            count++;

    return count;
}