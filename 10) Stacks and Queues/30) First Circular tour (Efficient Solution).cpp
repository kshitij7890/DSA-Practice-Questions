// O(n) time
// O(1) space
// 1 traversal only

#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

int tour(petrolPump p[],int n)
{
    int start=0,curr=0,prev=0;
    for(int i=0;i<n;i++)
    {
        curr+=p[i].petrol-p[i].distance;
        if(curr<0)
        {   start=i+1;
            prev+=curr;
            curr=0;
        }
    }
    
    if(prev+curr>=0) return start;
    else return -1;
}