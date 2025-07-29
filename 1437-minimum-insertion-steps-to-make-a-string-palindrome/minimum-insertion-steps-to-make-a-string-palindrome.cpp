class Solution {
public:
    int memo(int i,int j,string str1,string str2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(str1[i]==str2[j])
        {
            return 1+memo(i-1,j-1,str1,str2,dp);
        }
        int up=memo(i-1,j,str1,str2,dp);
        int left=memo(i,j-1,str1,str2,dp);
        return dp[i][j]=max(up,left);
    }
    int tabu(int n,string str1,string str2,vector<vector<int>>&dp)
    {
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    int up=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=max(up,left);
                }
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        int n=s.size();
        string str= s;
        reverse(str.begin(),str.end());
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // int ans=memo(n-1,n-1,s,str,dp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=tabu(n,s,str,dp);
        return n-ans;
    }
};