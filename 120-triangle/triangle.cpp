class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&triangle)
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
        int down=memo(i+1,j,dp,triangle);
        int dia=memo(i+1,j+1,dp,triangle);
        return dp[i][j]=min(down,dia)+triangle[i][j];
    }
    int tabu(vector<vector<int>>&dp,vector<vector<int>>&triangle)
    {
        int n=triangle.size();
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                int down=dp[i+1][j];
                int diag=dp[i+1][j+1];
                dp[i][j]=min(down,diag)+triangle[i][j];
            }
        }
        return dp[0][0];
    }
    int space(vector<vector<int>>&triangle,vector<int>&dp)
    {
        int n=triangle.size();
        for(int j=0;j<n;j++)
        {
            dp[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int>temp(n,-1);
            for(int j=0;j<=i;j++)
            {
                int down=dp[j];
                int diag=dp[j+1];
                temp[j]=min(down,diag)+triangle[i][j];
            }
            dp=temp;
        }
        return dp[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return memo(0,0,dp,triangle);
        // return tabu(dp,triangle);
        vector<int>dp(n,-1);
        return space(triangle,dp);
    }
};