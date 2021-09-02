bool comp(vector<int> &a,vector<int> &b)
{
    if(a[1]==b[1])
        return a[0]<b[0];
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end(),comp);
        int count=1;
        int temp=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=temp)
                continue;
            else
            {
                count++;
                temp=points[i][1];    
            }
        }
        
        return count;
    }
    
};