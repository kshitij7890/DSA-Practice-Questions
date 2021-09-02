/* 
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output: 240.00
Explanation: Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool myCmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, myCmp);
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            res += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            res += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {

        int n, W;
        cin >> n >> W;

        Item arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        cout << fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}