//TC : O(N^2)
//AS : O(N)

#include <bits/stdc++.h>
using namespace std;

int triplet(int n, int x, vector<int> arr)
{
    for (int i = 0; i < n - 2; i++)
    {
        unordered_set<int> s;
        int currsum = x - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(currsum - arr[j]) != s.end())
            {
                return 1;
            }
            s.insert(arr[j]);
        }
    }

    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << triplet(n, x, arr) << endl;
    }
    return 0;
}