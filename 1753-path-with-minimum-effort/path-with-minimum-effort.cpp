class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        while(!pq.empty())
        {
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==n-1&&c==m-1)
            {
                return d;
            }
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int neweffort=max(abs(heights[r][c]-heights[nrow][ncol]),d);
                    if(neweffort<dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};