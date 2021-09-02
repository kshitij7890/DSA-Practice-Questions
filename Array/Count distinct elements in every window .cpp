/*

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> result = countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

vector<int> countDistinct(int arr[], int n, int k)
{
    unordered_map<int, int> um;
    vector<int> vec;
    int dist_count = 0;
    for (int i = 0; i < k; i++)
    {
        if (um[arr[i]] == 0)
            dist_count++;

        um[arr[i]]++;
    }

    vec.push_back(dist_count);

    for (int i = k; i < n; i++)
    {
        if (um[arr[i - k]] == 1)
        {
            um[arr[i - k]]--;
            dist_count--;
        }
        else
        {
            um[arr[i - k]]--;
        }

        if (um[arr[i]] == 0)
        {
            um[arr[i]]++;
            dist_count++;
        }
        else
        {
            um[arr[i]]++;
        }

        vec.push_back(dist_count);
    }
    return vec;
}

/*

Algorithm:
1) Create an empty hash map. Let the hash map be hM.
2) Initialize the count of distinct element as dist_count to 0.
3) Traverse through the first window and insert elements of the first window to hM. The elements are used as key and their counts as the value in hM. Also, keep updating dist_count
4) Print distinct count for the first window.
5) Traverse through the remaining array (or other windows).
6) Remove the first element of the previous window.
    a) If the removed element appeared only once, remove it from hM and decrease the distinct count, i.e. do “dist_count–“
    b) else (appeared multiple times in hM), then decrement its count in hM
7) Add the current element (last element of the new window)
    a)  If the added element is not present in hM, add it to hM and increase the distinct count, i.e. do “dist_count++”
    b)  Else (the added element appeared multiple times), increment its count in hM

*/