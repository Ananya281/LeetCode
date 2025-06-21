class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        vector<int>row={-1,0,+1,0};
        vector<int>col={0,+1,0,-1};
        while(!pq.empty())
        {
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            if(r==n-1 && c==m-1)
            {
                return d;
            }
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int efforts=max(abs(heights[nrow][ncol]-heights[r][c]),d);
                    if(efforts<dis[nrow][ncol])
                    {
                        dis[nrow][ncol]=efforts;
                        pq.push({efforts,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};