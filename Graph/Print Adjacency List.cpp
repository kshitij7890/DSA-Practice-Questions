// Print Adjacency List

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>>printGraph(int V, vector<int> adj[])
	{
	    vector<vector<int>>v1;
	    
	    for(int i=0;i<V;i++)
	    {   vector<int>v2;
	    	v2.push_back(i);
	        for(int x:adj[i])
	        {
	            v2.push_back(x);
	        }

	        v1.push_back(v2);
	    }
	    return v1;
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
		vector<vector<int>>ans=obj.printGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	for(int j=0;j<ans[i].size()-1;j++){
        		cout<<ans[i][j]<<"-> ";
        	}
        	cout<<ans[i][ans[i].size()-1];
        	cout<<endl;
        }
	}
	return 0;
}