/*

Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, and a number X is given. 
The task is to find whether element X is present in the matrix or not.

Example 1:

Input:
N = 3, M = 3
mat[][] = 3 30 38 
         44 52 54 
         57 60 69
X = 62
Output: 0 

Explanation: 
62 is not present in the matrix, so output is 0

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matSearch(vector<vector<int>> &mat, int n, int m, int x)
    {
        int smallest = mat[0][0], largest = mat[n - 1][m - 1];
        if (x < smallest || x > largest)
            return 0;

        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (mat[i][j] == x)
                return 1;
            if (mat[i][j] < x)
                i++;
            else
                j--;
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int x;
        cin >> x;
        Solution ob;
        cout << ob.matSearch(arr, n, m, x) << endl;
    }
}

/*

Efficient Approach: The simple idea is to remove a row or column in each comparison until an element is found. 
Start searching from the top-right corner of the matrix. There are three possible cases. 

1) The given number is greater than the current number: This will ensure, that all the elements in the current row are smaller than the given number 
   Thus, the entire row gets eliminated and continue the search on the next row. Here elimination means that row needs not to be searched.

2) The given number is smaller than the current number: This will ensure, that all the elements in the current column are greater than the given number. 
   Thus, the entire column gets eliminated and continue the search on the previous column i.e. the column at the immediate left.

3) The given number is equal to the current number: This will end the search.

*/