class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)
        {
            return -1;
        }
        q.push({1,{0,0}});
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=1;
        int drow[8]={-1,-1,-1,0,+1,+1,+1,0};
        int dcol[8]={-1,0,+1,+1,+1,0,-1,-1};
        while(!q.empty())
        {
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==n-1)
            {
                return d;
            }
            for(int i=0;i<8;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && d+1<dis[nrow][ncol])
                {
                    dis[nrow][ncol]=d+1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};