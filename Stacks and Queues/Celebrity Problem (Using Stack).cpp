/* Watch PepCoding Video
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. 
Here M[i][i] will always be 0. Note: Follow 0 based indexing.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
(Stack Approach)
Time Complexity: O(N)
Auxiliary Space: O(N)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        while (s.size() >= 2)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (mat[a][b] == 1)
            { // a knows b --> a is not a celebrity
                s.push(b);
            }
            else
            { // a does not know b --> b is not a celebrity
                s.push(a);
            }
        }

        int pot = s.top();
        s.pop();

        for (int i = 0; i < n; i++)
        {
            if (i != pot)
            {
                if (mat[i][pot] != 1 || mat[pot][i] == 1)
                {
                    return -1;
                }
            }
        }

        return pot;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}