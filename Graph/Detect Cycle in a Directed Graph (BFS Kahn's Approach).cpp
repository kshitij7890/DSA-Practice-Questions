// Detect Cycle in a Directed Graph (BFS Kahn's algo)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int>indegree(V,0);
	   	
	   	for(int i=0;i<V;i++)
	   	    for(int x:adj[i])
               indegree[x]++;

	   	queue<int>q;
	   	
	   	for(int i=0;i<V;i++)
	   	    if(indegree[i]==0)
	   	        q.push(i);
	   	        
	   	int count=0;
	   	while(!q.empty())
	   	{
	   	    int u=q.front();
	   	    q.pop();
	   	    for(int x:adj[u])
	   	    {
	   	        if(--indegree[x]==0)
	   	            q.push(x);
	   	    }
	   	    count++;
	   	}
	   	
	   	return (count!=V);
	}
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}