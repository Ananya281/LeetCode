class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&visited,int &result)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            int v=it.first;
            int d=it.second;
            result=min(result,d);
            if(!visited[v])
            {
                dfs(v,adj,visited,result);
            }
        }   
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<int>visited(n+1,0);
        int result=INT_MAX;
        dfs(1,adj,visited,result);
        return result;
    }
};