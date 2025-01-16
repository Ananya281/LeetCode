class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int d=it[2];
            dis[u][v]=d;
            dis[v][u]=d;
        }
        for(int i=0;i<n;i++)
        {
            dis[i][i]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                    {
                        if((dis[i][k]+dis[k][j])<dis[i][j])
                        {
                            dis[i][j]=dis[i][k]+dis[k][j];
                        }
                    }
                }
            }
        }
        int citycount=n;
        int citynum=-1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=citycount)
            {
                citycount=count;
                citynum=i;
            }
        }
        return citynum;
    }
};