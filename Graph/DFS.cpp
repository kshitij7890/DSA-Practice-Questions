#include<bits/stdc++.h>
using namespace std;

//g : adjacency list of graph
//N : number of vertices

vector<int> DFSRec(vector<int> g[], int s, bool visited[],vector<int>&ans) 
{ 	
    visited[s]=true;
    ans.push_back(s);
    
    for(int u:g[s]){
        if(visited[u]==false)
            DFSRec(g,u,visited,ans);
    }
    return ans;
}
vector <int> dfs(vector<int> g[], int N)
{
    bool visited[N]; 
    int s=0;
    vector<int>ans;
	for(int i = 0;i<N; i++) 
		visited[i] = false;
		
    return DFSRec(g,s,visited,ans);

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];

        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
} 