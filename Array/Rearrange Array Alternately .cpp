/*
----------------------------------------------------------------------------------------------------------------------------------------------------------
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, 
second should be min value, third should be second max, fourth should be second min and so on.
----------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 6
arr[] = {1,2,3,4,5,6}
Output: 6 1 5 2 4 3
Explanation: Max element = 6, min = 1, 
second max = 5, second min = 2, and 
so on... Modified array is : 6 1 5 2 4 3.

Example 2:

Input:
N = 11
arr[]={10,20,30,40,50,60,70,80,90,100,110}
Output:110 10 100 20 90 30 80 40 70 50 60
Explanation: Max element = 110, min = 10, 
second max = 100, second min = 20, and 
so on... Modified array is : 
110 10 100 20 90 30 80 40 70 50 60.
----------------------------------------------------------------------------------------------------------------------------------------------------------
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
----------------------------------------------------------------------------------------------------------------------------------------------------------

*/

#include <bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n)
{
    long long max = arr[n - 1] + 1;
    long long max_index = n - 1;
    long long min_index = 0;

    if (n == 1)
        return;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 || i == 0)
        {
            arr[i] = (arr[max_index] % max) * max + arr[i];
            max_index--;
        }

        if (i % 2 != 0)
        {
            arr[i] = (arr[min_index] % max) * max + arr[i];
            min_index++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= max;
    }
}

int main()
{
    int t;

    //testcases
    cin >> t;

    while (t--)
    {

        //size of array
        int n;
        cin >> n;

        long long arr[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        //calling rearrange() function
        rearrange(arr, n);

        //printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}

/*

ALGORITHM USED :

Dividend = (Quotient * Divisor) + Remainder
where 
Dividend = Number to be stored in array
Quotient = new value that we want
Divisor = max value (In our case it is max value of the whole array + 1 )
Remainder = old value

At even Places :
arr[i] = ( (arr[max_index] % max) * max ) + arr[i]
max_index--

At odd Places :
arr[i] = ( (arr[min_index] % max) * max ) + arr[i]
min_index++

Eg : 1 2 3 4 5 6 
Number stored at arr[0] will be 6 * 7 + 1 = 43 so that ,
43 / 7 = new value = 6
43 % 7 = old value = 1

Similarly for other places also...in the array

*/