class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid)
    {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(i<0 || j<0)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return 1;
        }
        if(obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int top=memo(i-1,j,dp,obstacleGrid);
        int left=memo(i,j-1,dp,obstacleGrid);
        return dp[i][j]=top+left;
    }
    int tabu(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int top=0;
                    if(i>0)
                    {
                        top=dp[i-1][j];
                    }
                    int left=0;
                    if(j>0)
                    {
                        left=dp[i][j-1];
                    }
                    dp[i][j]=top+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
    int space(int n,int m,vector<int>&dp,vector<vector<int>>&obstacleGrid)
    {
        for(int i=0;i<n;i++)
        {
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    temp[j]=0;
                }
                else if(i==0 && j==0)
                {
                    temp[j]=1;
                }
                else
                {
                    int top=0;
                    if(i>0)
                    {
                        top=dp[j];
                    }
                    int left=0;
                    if(j>0)
                    {
                        left=temp[j-1];
                    }
                    temp[j]=top+left;
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // int ans=memo(n-1,m-1,dp,obstacleGrid);
        // int ans=tabu(n,m,dp,obstacleGrid);
        vector<int>dp(m,-1);
        int ans=space(n,m,dp,obstacleGrid);
        return ans;
    }
};