class Solution {
public:
    void bfs(vector<vector<int>>&mat,vector<vector<int>>&vis,vector<vector<int>>&dis,queue<pair<pair<int,int>,int>>&q)
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
            dis[r][c]=d;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]!=1)
                {
                    q.push({{nrow,ncol},d+1});
                    vis[nrow][ncol]=1;
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
                if(mat[i][j]==0)
                {
                    if(!vis[i][j])
                    {
                        q.push({{i,j},0});
                        vis[i][j]=1;
                    }
                }
            }
        }
        bfs(mat,vis,dis,q);
        return dis;
    }
};