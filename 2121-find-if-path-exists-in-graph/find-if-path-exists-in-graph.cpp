class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(source);
        vector<int>visited(n,-1);
        visited[source]=1;
        while(!q.empty())
        {
            int node=q.front();
            if(node==destination)
            {
                return true;
            }
            q.pop();
            for(auto it:adj[node])
            {
                if(visited[it]==-1)
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return false;
    }
};