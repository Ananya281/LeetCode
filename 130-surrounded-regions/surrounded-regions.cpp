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
        for(int i=0;i<n;i++)//row vary
        {
            if(!vis[i][0]&&board[i][0]=='O')//first col
            {
                q.push({i,0});
                vis[i][0]=1;
            }
            if(!vis[i][m-1]&&board[i][m-1]=='O')//last col
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i]&&board[0][i]=='O')
            {
                q.push({0,i});
                vis[0][i]=1;
            }
            if(!vis[n-1][i]&&board[n-1][i]=='O')
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
                if(!vis[i][j]&&board[i][j]=='O')
                {
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }
    }
};