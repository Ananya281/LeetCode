class Solution {
public:
    vector<vector<int>>bfs(queue<pair<int,pair<int,int>>>&q,vector<vector<int>>&mat,vector<vector<int>>&dis,vector<vector<int>>&vis)
    {
        int row[4]={-1,0,+1,0};
        int col[4]={0,+1,0,-1};
        int n=mat.size();
        int m=mat[0].size();
        while(!q.empty())
        {
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            dis[r][c]=d;
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        return dis;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && mat[i][j]==0)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        bfs(q,mat,dis,vis);
        return dis;
    }
};