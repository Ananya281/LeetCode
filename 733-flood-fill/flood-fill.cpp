class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>&image,int color,vector<vector<int>>&copy,int initial)
    {
        queue<pair<int,int>>q;
        int n=image.size();
        int m=image[0].size();
        q.push({sr,sc});
        copy[sr][sc]=color;
        vector<int>row={-1,0,+1,0};
        vector<int>col={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial && copy[nrow][ncol]!=color)
                {
                    copy[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>copy=image;
        int initial=image[sr][sc];
        bfs(sr,sc,image,color,copy,initial);
        return copy;
    }
};