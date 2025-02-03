class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0 || j>m-1)
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
        int up=matrix[i][j]+memo(i-1,j,dp,matrix);
        int rd=matrix[i][j]+memo(i-1,j+1,dp,matrix);
        int ld=matrix[i][j]+memo(i-1,j-1,dp,matrix);
        dp[i][j]=min({up,rd,ld});
        return dp[i][j];
    }
    int tabu(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&matrix)
    {
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int rd=matrix[i][j];
                if((j+1)<m)
                {
                    rd=rd+dp[i-1][j+1];
                }
                else
                {
                    rd=rd+1e9;
                }
                int ld=matrix[i][j];
                if(j-1>=0)
                {
                    ld=ld+dp[i-1][j-1];
                }
                else
                {
                    ld=ld+1e9;
                }
                dp[i][j]=min({up,rd,ld});
            }
        }
        int ans=1e9;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
    int space(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,-1);
        for(int j=0;j<m;j++)
        {
            prev[j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            vector<int>curr(m,-1);
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+prev[j];
                int rd=matrix[i][j];
                if((j+1)<m)
                {
                    rd=rd+prev[j+1];
                }
                else
                {
                    rd=rd+1e9;
                }
                int ld=matrix[i][j];
                if(j-1>=0)
                {
                    ld=ld+prev[j-1];
                }
                else
                {
                    ld=ld+1e9;
                }
                curr[j]=min({up,rd,ld});
            }
            prev=curr;
        }
        int ans=1e9;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,prev[j]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // for(int j=0;j<m;j++)
        // {
        //     ans=min(ans,memo(n-1,j,dp,matrix));
        // }
        // return tabu(n,m,dp,matrix);
        // return ans;
        return space(matrix);
    }
};