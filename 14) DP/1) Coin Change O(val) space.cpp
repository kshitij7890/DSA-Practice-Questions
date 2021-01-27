/*
Expected Time Complexity: O(Number of Coins * Value)
Expected Auxiliary Space: O(Value)

Example :
val = 4
n = 3
coins = {1,2,3}
Output = 4

Explanation :
coinSet={1,2,3}

ways={1,0,0,0,0} at start
       |
ways={1,1,1,1,1} when coin=1 
       |
ways={1,1,2,2,3} when coin=2 
       |
ways={1,1,2,3,4} when coin=3

*/
#include <bits/stdc++.h>
using namespace std;

long long numberOfWays(int coins[], int n, int val)
{
    //creating an array of ways
    long long ways[val + 1] = {0};

    //initializing ways to make 0 to 1
    ways[0] = 1;
    vector<int> coinsSet;

    //pushing elements to the coinSet
    for (int i = 0; i < n; i++)
    {
        coinsSet.push_back(coins[i]);
    }

    //running a loop for coinsSet
    for (auto coin : coinsSet)
    {
        //running a loop for value
        for (int i = 1; i < val + 1; i++)
        {
            //if coin value is less
            //than ith value
            if (i >= coin)
            {
                //incrementing number of ways
                ways[i] += ways[i - coin];
            }
        }
    }

    //returning number of ways
    //of value
    return ways[val];
}

int main()
{

    //taking total count of testcases
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        //taking value
        int value;
        cin >> value;

        //taking number of coins
        int numberOfCoins;
        cin >> numberOfCoins;
        int coins[numberOfCoins];

        //inserting coins to the array
        for (int i = 0; i < numberOfCoins; i++)
            cin >> coins[i];

        //calling function numberOfWays
        cout << numberOfWays(coins, numberOfCoins, value) << endl;
    }
    return 0;
}