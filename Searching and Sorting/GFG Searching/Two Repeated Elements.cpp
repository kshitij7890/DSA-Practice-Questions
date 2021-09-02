/*

You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. Also, all elements occur once except two numbers which occur twice. 
Find the two repeating numbers.

Example 1:

Input : N = 4
array[] = {1,2,1,3,4,3}
Output: 1 3
Explanation: In the given array, 1 and 3 are repeated two times.

Example 2:

Input : N = 2
array[] = {1,2,2,1}
Output: 2 1
Explanation: In the given array,1 and 2 are repeated two times and second occurence of 2 comes before 1. 

*/

pair<int, int> twoRepeated(int arr[], int n)
{
    pair<int, int> p;
    int flag = 0;
    for (int i = 0; i < n + 2; i++)
    {
        if (arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
        {
            if (flag == 0)
            {
                p.first = abs(arr[i]);
                flag = 1;
            }
            else
                p.second = abs(arr[i]);
        }
    }

    return p;
}

/*

The complete Solution :

a) Traverse the complete array, take the array elements as index and mark the element at this index postion 
b) Marking can be done, for example by multiplying the element at this index by -1
c) Also, check if the element at this index is already negative, if it is output the index    
    
*/