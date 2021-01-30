/*

Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each 
element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, 
next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.

*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n);
    ans[n - 1] = -1;
    stack<long long> s;
    s.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        while (s.empty() == false and s.top() <= arr[i])
            s.pop();

        if (s.empty() == false)
            ans[i] = s.top();
        else
            ans[i] = -1;

        s.push(arr[i]);
    }

    //reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> res = nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}