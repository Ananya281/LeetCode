class Solution {
public:
    void dfs(int initial,vector<vector<int>>&image,vector<vector<int>>&result,int sr,int sc,int color)
    {
        int n=image.size();
        int m=image[0].size();
        result[sr][sc]=color;
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,+1,0,-1};

            for(int i=0;i<4;i++)
            {
                int nrow=sr+drow[i];
                int ncol=sc+dcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m && result[nrow][ncol]!=color && image[nrow][ncol]==initial)
                {
                    dfs(initial,image,result,nrow,ncol,color);
                }
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>result=image;
        int initial=image[sr][sc];
        dfs(initial,image,result,sr,sc,color);
        return result;
    }
};