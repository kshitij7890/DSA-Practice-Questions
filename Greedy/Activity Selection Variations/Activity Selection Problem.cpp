// Activity Selection Problem
// Given N activities with their start and finish times. 
// Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int,int>a,pair<int,int>b)
{
    return(a.second<b.second);
}

int activitySelection(int start[], int end[], int n){
    vector <pair<int,int>> vec;
    for(int i=0;i<n;i++)
    {
        vec.push_back(make_pair(start[i],end[i]));
    }
    sort(vec.begin(),vec.end(),myCmp);
    int res=1;
    int prev=0;
    for(int curr=1;curr<n;curr++)
    {
        if (vec[curr].first>=vec[prev].second)
        {
            res++;
            prev=curr;
        }
        else
        {
            continue;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        
        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}