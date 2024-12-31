class Solution {
public:
    void bfs(queue<pair<pair<int,int>,int>>&q,vector<vector<int>>&dis,vector<vector<int>>&vis,vector<vector<int>>&mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dis[r][c]=d;
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        vector<vector<int>>dis(n,vector<int>(m));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0&&!vis[i][j])
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        bfs(q,dis,vis,mat);
        return dis;
    }
};