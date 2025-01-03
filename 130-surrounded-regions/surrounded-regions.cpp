class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        int drow[4]={-1,0,+1,0};
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        int dcol[4]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();//rows
        int m=board[0].size();//col
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)//row vary
        {
            if(!vis[i][0]&&board[i][0]=='O')//first col
            {
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1]&&board[i][m-1]=='O')//last col
            {
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i]&&board[0][i]=='O')
            {
                dfs(0,i,vis,board);
            }
            if(!vis[n-1][i]&&board[n-1][i]=='O')
            {
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&board[i][j]=='O')
                {
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }
    }
};