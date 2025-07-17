class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0 || grid[0][0]==1 || grid[n-1][n-1]==1)
        {
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        vector<int>row={-1,-1,0,+1,+1,+1,0,-1};
        vector<int>col={0,+1,+1,+1,0,-1,-1,-1};
        int level=1;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r==n-1 && c==n-1)
                {
                    return level;
                }
                for(int i=0;i<8;i++)
                {
                    int nrow=r+row[i];
                    int ncol=c+col[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0)
                    {
                        grid[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};