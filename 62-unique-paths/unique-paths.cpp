class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp)
    {
        if(i<0||j<0)
        {
            return 0;
        }
        if(i==0&&j==0)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int top=memo(i-1,j,dp);
        int left=memo(i,j-1,dp);
        return dp[i][j]=top+left;
    }
    int tabu(int m,int n,vector<vector<int>>&dp)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    int left=0;
                    if(j-1>=0)
                    {
                        left=dp[i][j-1];
                    }
                    int top=0;
                    if(i-1>=0)
                    {
                        top=dp[i-1][j];
                    }
                    dp[i][j]=top+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int space(int m,int n,vector<int>&dp)
    {
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j]=1;
                }
                else
                {
                    int left=0;
                    if(j-1>=0)
                    {
                        left=temp[j-1];
                    }
                    int top=0;
                    if(i-1>=0)
                    {
                        top=dp[j];
                    }
                    temp[j]=left+top;
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return memo(m-1,n-1,dp);
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // return tabu(m,n,dp);
        vector<int>dp(n,0);
        return space(m,n,dp);
    }
};