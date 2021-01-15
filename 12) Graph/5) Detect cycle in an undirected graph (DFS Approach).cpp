// Detect cycle in an undirected graph (DFS Approach)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int s, vector<int>adj[], int parent,bool visited[])
    {
        visited[s]=true;
        for(int x:adj[s])
        {
            if(visited[x]==false)
            {
                if(dfs(x,adj,s,visited)==true)
                return true;
            }
            else if(x!=parent)
            {
                return true;
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    int parent=-1;
	    bool visited[V+1];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(dfs(i,adj,-1,visited)==true) return true;
	        }
	    }
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 