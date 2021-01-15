#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int v, vector<int> adj[])
    {
        vector<int> ans;
        queue<int> q;
        bool visited[v + 1];
        visited[0] = true;
        q.push(0);
        while (q.empty() == false)
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : adj[u])
            {
                if (visited[v] == false)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 	adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}