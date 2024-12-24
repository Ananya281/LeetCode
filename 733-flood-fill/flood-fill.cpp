class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&copy,int initial,int color)
    {
        int n=image.size();
        int m=image[0].size();
        copy[sr][sc]=color;
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};

        for(int i=0;i<4;i++)
            {
                int nrow=sr+drow[i];
                int ncol=sc+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==initial&&copy[nrow][ncol]!=color)
                {
                    dfs(nrow,ncol,image,copy,initial,color);
                }
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        vector<vector<int>>copy=image;
        dfs(sr,sc,image,copy,initial,color);
        return copy;
    }
};