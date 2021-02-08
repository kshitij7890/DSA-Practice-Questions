/*

Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it. 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after 
sorting it in wave form are 
2 1 4 3 5.
 

Example 2:

Input:
N = 6
arr[] = {2,4,7,8,9,10}
Output: 4 2 8 7 10 9
Explanation: Array elements after 
sorting it in wave form are 
4 2 8 7 10 9.

*/

void convertToWave(int *arr, int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (n % 2 != 0 && i == n - 1)
            break;
        swap(arr[i], arr[i + 1]);
    }
}