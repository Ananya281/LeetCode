class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        int drow[4]={-1,0,+1,0};
        int n=board.size();
        int m=board[0].size();
        int dcol[4]={0,+1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O')
            {
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n=board.size();//rows
        int m=board[0].size();//col
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||i==n-1||j==0||j==m-1)
                {
                    if(board[i][j]=='O'&&!vis[i][j])
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        bfs(q,vis,board);
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