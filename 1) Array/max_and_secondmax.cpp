#include <bits/stdc++.h>
using namespace std;

vector<int> largestAndSecondLargest(int, int[]);

vector<int> largestAndSecondLargest(int n, int arr[]){
    int max1 = INT_MIN, max2= INT_MIN;

     for(int i=0;i<n;i++)
     {
         max1=max(max1,arr[i]);
     }
     for(int i=0;i<n;i++)
     {
         if(arr[i]!=max1)
         {
             max2=max(max2,arr[i]);
         }
     }
     
      if(max2==INT_MIN)
     max2=-1;
     
     vector<int>a(2);
     a[0]=max1;
     a[1]=max2;
  
     return a;
     
}

int main() {
	

	int testcases;
	cin >> testcases;

	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];

	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
} 