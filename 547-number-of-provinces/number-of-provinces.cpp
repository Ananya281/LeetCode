class Solution {
public:
    void bfs(int node,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=1;
        int n=adj.size();
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto it:adj[ele])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1&&i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i,adj,vis);
            }
        }
        return count;
    }
};