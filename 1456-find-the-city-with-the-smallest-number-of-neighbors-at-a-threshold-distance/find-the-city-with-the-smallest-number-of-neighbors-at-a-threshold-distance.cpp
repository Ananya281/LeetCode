class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(adj[j][i]!=INT_MAX && adj[i][k]!=INT_MAX)
                    {
                        adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
                    }
                }
            }
        }
        int citycount=n;
        int cityno=-1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=citycount)
            {
                citycount=count;
                cityno=i;
            }
        }
        return cityno;
    }
};