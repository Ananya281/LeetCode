class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&copy,int initial,int color)
    {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        copy[sr][sc]=color;
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
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==initial&&copy[nrow][ncol]!=color)
                {
                    copy[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        vector<vector<int>>copy=image;
        bfs(sr,sc,image,copy,initial,color);
        return copy;
    }
};