class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<int>&vis,int start)
    {
        int n=adj.size();
        queue<int>q;
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
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
     int count=0;
     vector<int>vis(n,0);
     for(int i=0;i<n;i++)
     {
        if(!vis[i])
        {
            count++;
            bfs(adj,vis,i);
        }
     }
     return count;
    }
};