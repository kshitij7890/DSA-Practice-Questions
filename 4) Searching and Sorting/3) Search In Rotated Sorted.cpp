#include <iostream>
#include<vector>
using namespace std;


int search(vector<int>& nums, int target) 
{
    int low=0, high=nums.size()-1;
        
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        
        if(nums[mid]>nums[low]) //left half sorted
        {
           if(target<nums[mid] && target>=nums[low])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else //right half sorted
        {
            if(target>nums[mid] && target<=nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
return -1;
}    

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n;
	    vector<int>nums(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>nums[i];
	    }
	    cin>>k;
	    
	    cout<<search(nums,k)<<endl;
	}
	return 0;
}