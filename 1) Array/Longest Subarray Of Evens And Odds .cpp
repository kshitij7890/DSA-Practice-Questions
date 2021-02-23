/*

You are given an array of size n. 
Find the maximum possible length of a subarray such that its elements are arranged alternately either as even and odd or odd and even .

Example 1:

Input:
n = 5
a[] = {10,12,14,7,8}
Output: 3
Explanation: The max length of subarrayis 3 and the subarray is {14 7 8}. 
Here the array starts as an even element and has odd and even elements alternately.

*/

int maxEvenOdd(int arr[], int n)
{
    int count = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            count = count + 1;
            res = max(count, res);
        }
        else
            count = 1;
    }

    return res;
}

/*

LOGIC : KADANE ALGO VARIANT
Check for alternate odd and even numbers. In that case keep increasing the counter and storing the maximum length.
As soon as you get two continuous odd or even numbers change the counter to 1.

*/