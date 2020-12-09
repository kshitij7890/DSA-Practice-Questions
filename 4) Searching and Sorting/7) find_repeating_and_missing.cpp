#include <bits/stdc++.h>
using namespace std;

//TC : O(n) 
//AS : O(1)

/* APPROACH : Traverse the array. 
While traversing, use the absolute value of every element as an index and 
make the value at this index as negative to mark it visited. 
If something is already marked negative then this is the repeating element. 
To find missing, traverse the array again and look for a positive value.*/

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *res = new int[2];
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                res[0] = abs(arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                res[1] = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}