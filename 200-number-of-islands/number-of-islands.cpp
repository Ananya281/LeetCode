class Solution {
public:
    void bfs(int dr,int dc,vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        int row[4]={-1,0,+1,0};
        int col[4]={0,+1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({dr,dc});
        visited[dr][dc]=1;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]==-1)
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==-1)
                {
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
