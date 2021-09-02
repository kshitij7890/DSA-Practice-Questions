// Count ways to N'th Stair(Order does not matter)
------------------------------------------------------------------------------------------------------------------------------
/* SIMPLE SOLUTION

Consider that you have N stairs. First of all you have to understand if N is odd or even.

If is even than it will be a multiple of 2: N = 2*S, where S is the number of pair of stairs.
Suppose N = 6 and S = 3. Your first solution is {2,2,2}. 
Then you can change the first 2 stairs with 1 + 1 stairs and you have your second solution {1, 1, 2 ,2}. 
Since order doesn't matter let's proceed with the next pair and we have our third solution {1, 1, 1, 1, 2} and 
then the fourth {1, 1, 1, 1, 1, 1}
Given N = 2*S the number of possible solutions are S + 1.

Now suppose N is odd and N = 2S + 1. Let N = 7 and S = 3. 
Our solutions are {2,2,2,1}, {1,1,2,2,1}, {1,1,1,1,2,1} and {1,1,1,1,1,1,1}. 
Again, the number of solutions is given by S+1

Now your algorithm is pretty simple:
ANSWER ----> return N/2 + 1

*/
-------------------------------------------------------------------------------------------------------------------------------
long long countWays(int n)
{
   return (n/2)+1;
}
-------------------------------------------------------------OR----------------------------------------------------------------

/* DP SOLUTION

The above answer is correct, but if you want to know how DP is used in this problem, look at this example:

jumps =[1,2]
Lets say that jump =1, so for any stair, the number of ways will always be equal to 1.

Now for jump=2, say for stair 8: no of ways will be (no of ways to reach 8 using 1 only) +
(no of ways to reach 6 using both 1 and 2 because you can reach to 8 from 6 by just a jump of 2).

So the code will looks like:

 for(int i=1; i<=n;i++)
     dp[i]=1;

for(int i=2;i<=n;i++)
    dp[i]=dp[i]+dp[i-2];

return dp[n];

*/
--------------------------------------------------------------------------------------------------------------------------------
long long countWays(int n)
{
    int dp[n+1];
    dp[0]=1;
    for(int i=1; i<=n;i++)
    dp[i]=1;

    for(int i=2;i<=n;i++)
    dp[i]=dp[i]+dp[i-2];

return dp[n];

}
--------------------------------------------------------------------------------------------------------------------------------