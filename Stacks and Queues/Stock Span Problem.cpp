/*

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price 
for all n days. The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which 
the price of the stock on the current day is less than or equal to its price on the given day.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate span
// price[]: price array in input
// n: size of array
vector<int> calculateSpan(int *price, int n)
{
    vector<int> span(n);
    stack<int> s;

    span[0] = 1;
    s.push(0);

    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false and price[s.top()] <= price[i])
            s.pop();

        if (s.empty() == false)
            span[i] = i - s.top();
        else
            span[i] = i + 1;

        s.push(i);
    }
    return span;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> s = calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}