#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}

//BINARY SEARCH METHOD
//Traverse through the array , if element is greater than the previous element
//simply append it , else find the ceil value of of that element in the tail array
// and replace that ceil value with the element , at last len of tail array is the answer.

int ceilvalue(vector<int> tail, int l, int r, int key)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int longestSubsequence(int n, int a[])
{
    vector<int> tail;
    tail.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > tail.back())
        {
            tail.push_back(a[i]);
        }
        else
        {
            int c = ceilvalue(tail, 0, tail.size(), a[i]);
            tail[c] = a[i];
        }
    }

    return tail.size();
}