#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int first, int last)
{
    while (first < last)
    {
        swap(arr[first], arr[last]);
        first++;
        last--;
    }
}

void rotate(vector<int> &arr, int first, int last)
{
    reverse(arr, 0, arr.size() - 2);
    reverse(arr, 0, arr.size() - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        rotate(arr, 0, n - 1);

        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    return 0;
}