/*

Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Example 1:

Input:
N = 4
arr[] = {3,4,1,2}
Output: Yes
Explanation: The array is sorted (1, 2, 3, 4) and rotated twice (3, 4, 1, 2).

Example 2:

Input:
N = 3
arr[] = {1,2,3}
Output: No
Explanation: The array is sorted (1, 2, 3) is not rotated.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////
class Solution
{
public:
    // Function to find index of Maximum element in an array
    int maximum(int arr[], int n)
    {
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[maxi])
                maxi = i;
        }
        return maxi;
    }
    // Function to find index of Minimum element in an array
    int minimum(int arr[], int n)
    {
        int mini = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[mini])
                mini = i;
        }
        return mini;
    }
    // Function to check if array is rotated and sorted
    bool checkRotatedAndSorted(int arr[], int n)
    { //////////////////////////////////////////////////////////////
        int mini = minimum(arr, n);
        int maxi = maximum(arr, n);
        int flag1 = 0, flag2 = 0;

        // To check whether it can be increasing sorted & rotated or decreasing sorted & rotated
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[mini] && arr[i + 1] == arr[maxi])
                flag2 = 1; // can be decreasing sorted & rotated (more conditions required to confirm it)
            else if (arr[i] == arr[maxi] && arr[i + 1] == arr[mini])
                flag1 = 1; // can be increasing sorted & rotated (more conditions required to confirm it)
        }

        // If neither of them return false
        if (flag1 == 0 && flag2 == 0)
            return 0;

        //////////////////////////////////////////////////////////////
        if (flag1 == 1)
        {
            int temp1 = 1;
            //---------------------------------------------------
            for (int i = 1; i < mini; i++)
            {
                if (arr[i] < arr[i - 1])
                {
                    temp1 = 0;
                    break;
                }
            }

            int temp2 = 1;
            // ---------------------------------------------------

            for (int i = mini + 1; i < n; i++)
            {
                if (arr[i] < arr[i - 1])
                {
                    temp2 = 0;
                    break;
                }
            }

            // ---------------------------------------------------

            if (temp1 && temp2 && (arr[n - 1] < arr[0]))
                return 1;
            else
                return 0;
        }

        //////////////////////////////////////////////////////////////
        else if (flag2 == 1)
        {
            int temp1 = 1;

            // ---------------------------------------------------
            for (int i = 1; i < maxi; i++)
            {
                if (arr[i] > arr[i - 1])
                {
                    temp1 = 0;
                    break;
                }
            }

            int temp2 = 1;

            // ---------------------------------------------------

            for (int i = maxi + 1; i < n; i++)
            {
                if (arr[i] > arr[i - 1])
                {
                    temp2 = 0;
                    break;
                }
            }
            // ---------------------------------------------------

            if (temp1 && temp2 && (arr[n - 1] > arr[0]))
                return 1;
            else
                return 0;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int T;
    //testcases
    cin >> T;

    while (T--)
    {
        int num;
        //size of array
        cin >> num;
        int arr[num];

        //inserting elements
        for (int i = 0; i < num; ++i)
            cin >> arr[i];

        bool flag = false;
        Solution ob;

        //function call
        flag = ob.checkRotatedAndSorted(arr, num);

        //printing "No" if not sorted and
        //rotated else "Yes"
        if (!flag)
        {
            cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
    }

    return 0;
}

/*////////////////////////////////////////////////////////////////////////////////////////

HINT 1 :
Array is sorted, so it can be Decreasingly sorted or Increasingly sorted.
Check for both.

////////////////////////////////////////////////////////////////////////////////////////*/
/*

HINT 2 :
So How to Find, if array is Decreasingly or Increasingly Sorted in a Sorted and Rotated Array.
Simple,
If the positon of Max. Element is just before Min. Element, then it is Increasingly Sorted
Else if position of Max. Element is just after Min. Element then it is Decreasingly Sorted,
Else it is not sorted and rotated.
So now What to do..??

/////////////////////////////////////////////////////////////////////////////////////////*/
/*

HINT 3 :
After the previous Hint, the question only remains to check for any other irregularity.

In case of Increasingly Sorted,

Check if array is increasing upto Max. Element
Check if array is increasing again after Min Element
Check if Last Element is smaller than the first element
In case of Decreasingly Sorted,

Check if array is decreasing upto Min. Element
Check if array is decreasing again after Max Element
Check if Last Element is larger than the first element
If all these conditions meet, the array is sorted and rotated

/////////////////////////////////////////////////////////////////////////////////////////*/