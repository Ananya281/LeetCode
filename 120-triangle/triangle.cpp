class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp)
    {
        int n=triangle.size();
        if(i==n-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int d=triangle[i][j]+memo(i+1,j,triangle,dp);
        int dg=triangle[i][j]+memo(i+1,j+1,triangle,dp);
        dp[i][j]=min(d,dg);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return memo(0,0,triangle,dp);
    }
};