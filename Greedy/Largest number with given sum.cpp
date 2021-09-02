/*

A boy lost the password of his super locker. 
He remembers the number of digits N as well as the sum S of all the digits of his password. 
He know that his password is the largest number of N digits that can be possible with given sum S. 
As he is busy doing his homework, help him retrieving his password.

*/

#include <bits/stdc++.h>
using namespace std;

string largestNumber(int n, int sum)
{
    if(sum > n*9) return to_string(-1);
    string str;
    
    while(sum>9)
    {
        str.append(to_string(9));
        sum=sum-9;
        n=n-1;
    }
    
    if(sum<=9)
    {   str.append(to_string(sum));
        for(int i=0;i<n-1;i++)
        {
            str.append(to_string(0));
        }
        return str;
    }

    
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,sum;
		cin>>n>>sum;
		cout<<largestNumber(n, sum)<<endl;
	}
	return 0;
}

/*

Example 1:
Input:
N = 5, S = 12
Output:
93000
Explanation:
Sum of elements is 12.
Largest possible 5 digit number is 93000

Example 2:
Input:
N = 3, S = 29
Output:
-1
Explanation:
There is no such three digit
number whose sum is 29.

*/