class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        if(i<0 || j<0)
        {
            return 1e9;
        }
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int top=memo(i-1,j,dp,grid);
        int left=memo(i,j-1,dp,grid);
        return dp[i][j]=grid[i][j]+min(top,left);
    }
    int tabu(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int top=1e9;
                    if(i>0)
                    {
                        top=dp[i-1][j];
                    }
                    int left=1e9;
                    if(j>0)
                    {
                        left=dp[i][j-1];
                    }
                    dp[i][j]=min(left,top)+grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
    int space(int n,int m,vector<int>&dp,vector<vector<int>>&grid)
    {
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j]=grid[i][j];
                }
                else
                {
                    int top=1e9;
                    if(i>0)
                    {
                        top=dp[j];
                    }
                    int left=1e9;
                    if(j>0)
                    {
                        left=temp[j-1];
                    }
                    temp[j]=min(top,left)+grid[i][j];
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,grid);
        // return tabu(n,m,dp,grid);
        vector<int>dp(m,-1);
        return space(n,m,dp,grid);
    }
};