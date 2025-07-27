class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&matrix)
    {
        int m=matrix[0].size();
        if(j<0 || j>=m)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int top=memo(i-1,j,dp,matrix)+matrix[i][j];
        int leftdia=memo(i-1,j-1,dp,matrix)+matrix[i][j];
        int rightdia=memo(i-1,j+1,dp,matrix)+matrix[i][j];
        return dp[i][j]=min({top,leftdia,rightdia});
    }
    int tabu(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&matrix)
    {
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int top=matrix[i][j];
                if(i-1>=0)
                {
                    top=top+dp[i-1][j];
                }
                else
                {
                    top=top+1e9;
                }
                int left=matrix[i][j];
                if(i-1>=0 && j-1>=0)
                {
                    left=left+dp[i-1][j-1];
                }
                else
                {
                    left=1e9;
                }
                int right=matrix[i][j];
                if(i-1>=0 && j+1<n)
                {
                    right=right+dp[i-1][j+1];
                }
                else
                {
                    right=1e9;
                }
                dp[i][j]=min({top,left,right});
            }
        }
        int result=1e9;
        for(int i=0;i<m;i++)
        {
            result=min(result,dp[n-1][i]);
        }
        return result;
    }
    int space(int n,int m,vector<int>&dp,vector<vector<int>>&matrix)
    {
        for(int i=0;i<m;i++)
        {
            dp[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(m,-1);
            for(int j=0;j<m;j++)
            {
                int top=matrix[i][j];
                if(i-1>=0)
                {
                    top=top+dp[j];
                }
                else
                {
                    top=top+1e9;
                }
                int left=matrix[i][j];
                if(i-1>=0 && j-1>=0)
                {
                    left=left+dp[j-1];
                }
                else
                {
                    left=1e9;
                }
                int right=matrix[i][j];
                if(i-1>=0 && j+1<n)
                {
                    right=right+dp[j+1];
                }
                else
                {
                    right=1e9;
                }
                temp[j]=min({top,left,right});
            }
            dp=temp;
        }
        int result=1e9;
        for(int i=0;i<m;i++)
        {
            result=min(result,dp[i]);
        }
        return result;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // int ans=1e9;
        // for(int i=0;i<n;i++)//columns
        // {
        //     ans=min(ans,memo(n-1,i,dp,matrix));
        // }
        // return ans;
        return tabu(n,m,dp,matrix);
        // vector<int>dp(m,-1);
        // return space(n,m,dp,matrix);
    }
};