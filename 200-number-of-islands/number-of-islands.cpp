class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
         int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1')
                {
                    dfs(nrow,ncol,grid,vis);
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};