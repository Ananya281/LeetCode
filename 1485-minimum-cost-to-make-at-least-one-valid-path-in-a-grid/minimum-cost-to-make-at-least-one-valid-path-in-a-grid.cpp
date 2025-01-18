class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        int drow[4]={0,0,+1,-1};
        int dcol[4]={+1,-1,0,0};
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1)
            {
                return cost;
            }
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int ncost;
                    if(grid[r][c]==i+1)
                    {
                        ncost=cost;
                    }
                    else
                    {
                        ncost=cost+1;
                    }
                    if(ncost<dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=ncost;
                        pq.push({ncost,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
// m*n 1=right 2=left 3=lower 4=upper
// (0,0) (m-1,n-1)