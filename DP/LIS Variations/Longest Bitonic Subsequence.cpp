// LONGEST BITONIC SUBSEQUENCE (LIS VARIATION)
// Expected Time Complexity: O(n^2)
// Expected Space Complexity: O(n)


/* Let the input array be arr[] of length n. We need to construct two arrays lis[] and lds[] using Dynamic Programming solution of LIS problem. 
lis[i] stores the length of the Longest Increasing subsequence ending with arr[i]. lds[i] stores the length of the longest Decreasing subsequence 
starting from arr[i]. Finally, we need to return the max value of lis[i] + lds[i] – 1 where i is from 0 to n-1. */

int LongestBitonicSequence(vector<int>nums)
	{
	   ///////////////////////////////////////////////////////////
	   vector<int>lis(nums.size());  
	   lis[0]=1;
	   for(int i=1;i<nums.size();i++)
	   { lis[i]=1;
	       for(int j=0;j<i;j++)
	       {
	           if(nums[j]<nums[i])
	           {
	               lis[i]=max(lis[i],lis[j]+1);
	           }
	       }
	   }
	   ///////////////////////////////////////////////////////////
	   vector<int>lds(nums.size());  
	   lds[nums.size()-1]=1;
	   for(int i=nums.size()-2;i>=0;i--)
	   { lds[i]=1;
	       for(int j=nums.size()-1;j>i;j--)
	       {
	           if(nums[j]<nums[i])
	           {
	               lds[i]=max(lds[i],lds[j]+1);
	           }
	       }
	   }
	   ///////////////////////////////////////////////////////////
	    
	    int res=lis[0]+lds[0]-1;
	    for(int i=1;i<nums.size();i++)
	    {
	        res=max(res,lis[i]+lds[i]-1);
	    }
	    return res;
	}