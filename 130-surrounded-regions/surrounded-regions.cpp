class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        int n=board.size();
        int m=board[0].size();
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&board[nrow][ncol]=='O')
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
           if(board[i][0]=='O'&&!vis[i][0])
           {
                q.push({i,0});
                vis[i][0]=1;
           }
           if(board[i][m-1]=='O'&&!vis[i][m-1])
           {
                q.push({i,m-1});
                vis[i][m-1]=1;
           }
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O'&&!vis[0][i])
            {
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[n-1][i]=='O'&&!vis[n-1][i])
            {
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        bfs(q,vis,board);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }
    }
};