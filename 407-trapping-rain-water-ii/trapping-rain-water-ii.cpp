class Solution {
public:
void bfs(vector<vector<int>>&heightMap,vector<vector<int>>&vis,
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>&pq,int &water)
{
    int n=heightMap.size();
    int m=heightMap[0].size();
    int drow[4]={-1,0,+1,0};
    int dcol[4]={0,+1,0,-1};
    while(!pq.empty())
    {
        int h=pq.top().first;
        int r=pq.top().second.first;
        int c=pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
            {
                water=water + max(0,h-heightMap[nrow][ncol]);
                int newh=max(h,heightMap[nrow][ncol]);
                pq.push({newh,{nrow,ncol}});
                vis[nrow][ncol]=1;
            }
        }
    }
}
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int water=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(!vis[i][j])
                    {
                        vis[i][j]=1;
                        pq.push({heightMap[i][j],{i,j}});
                    }
                }
            }
        }
        bfs(heightMap,vis,pq,water);
        return water;
    }
};