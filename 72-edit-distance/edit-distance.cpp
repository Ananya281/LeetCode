class Solution {
public:
    int memo(int i,int j,vector<vector<int>>&dp,string word1,string word2)
    {
        if(i<0)
        {
            return j+1;
        }
        if(j<0)
        {
            return i+1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(word1[i]==word2[j])
        {
            return memo(i-1,j-1,dp,word1,word2);
        }
        int ins=memo(i,j-1,dp,word1,word2);
        int del=memo(i-1,j,dp,word1,word2);
        int rep=memo(i-1,j-1,dp,word1,word2);
        dp[i][j]=1+min(ins,min(del,rep));
        return dp[i][j];
    }
    int tabu(int n,int m,vector<vector<int>>&dp,string word1,string word2)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    int ins=dp[i][j-1];
                    int del=dp[i-1][j];
                    int rep=dp[i-1][j-1];
                    dp[i][j]=1+min({ins,del,rep});
                }
            }
        }
        return dp[n][m];
    }
    int space(int n, int m, vector<int>&dp,string word1, string word2)
    {
        for(int i=0;i<=m;i++)
        {
            dp[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            vector<int>temp(m+1,-1);
            temp[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    temp[j]=dp[j-1];
                }
                else
                {
                    int ins=temp[j-1];
                    int del=dp[j];
                    int rep=dp[j-1];
                    temp[j]=1+min({ins,del,rep});
                }
            }
            dp=temp;
        }
        return dp[m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,dp,word1,word2);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return tabu(n,m,dp,word1,word2);
        vector<int>dp(m+1,-1);
        return space(n,m,dp,word1,word2);
    }
};