class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>&vis,vector<vector<int>>&board)
    {
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};

            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&board[nrow][ncol]==1)
                {
                    dfs(nrow, ncol,vis,board);
                }
            }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
           if(grid[i][0]==1&&!vis[i][0])
           {
                dfs(i,0,vis,grid);
           }
           if(grid[i][m-1]==1&&!vis[i][m-1])
           {
                dfs(i,m-1,vis,grid);
           }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1&&!vis[0][i])
            {
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i]==1&&!vis[n-1][i])
            {
                dfs(n-1,i,vis,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                    vis[i][j]=1;
                }
            }
        }
        return count;
    }
};