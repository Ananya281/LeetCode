class Solution {
public:
    void dfs(int node,int parent, vector<int>&vis,vector<vector<int>>&adj,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges,int &timer)
    {
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
            {
                continue;
            }
            if(!vis[it])
            {
                dfs(it,node,vis,adj,tin,low,bridges,timer);
                low[node]=min(low[node],low[it]);
                if(tin[node]<low[it])
                {
                    bridges.push_back({node,it});
                }
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);
        vector<vector<int>>bridges;
        int timer=0;
        dfs(0,-1,vis,adj,tin,low,bridges,timer);
        return bridges;
    }
};