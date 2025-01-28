class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>&visited,vector<vector<int>>&grid)
    {
        int sum=grid[r][c];
        int n=grid.size();
        int m=grid[0].size();
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        visited[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]>0)
                {
                    sum=sum+grid[nrow][ncol];
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxsum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]>0)
                {
                    maxsum=max(maxsum,bfs(i,j,visited,grid));
                }
            }
        }
        return maxsum;
    }
};