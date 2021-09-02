/* QUES : You are given N pairs of numbers. In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
You have to find the longest chain which can be formed from the given set of pairs. */

//Expected Time Complexity: O(N*N)
//Expected Auxiliary Space: O(N)

#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
}

bool compare(struct val a, struct val b)
{
    return a.first < b.first;
}

int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, compare);
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (p[i].first > p[j].second)
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
    return res;
}