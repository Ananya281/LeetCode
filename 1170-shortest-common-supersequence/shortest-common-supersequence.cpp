class Solution {
public:
    int tabu(int n,int m,string str1,string str2,vector<vector<int>>&dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    int up=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=max(up,left);
                }
            }
        }
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=n+m-tabu(n,m,str1,str2,dp);
        int i=n;
        int j=m;
        int index=ans-1;
        string str;
        for(int i=0;i<ans;i++)
        {
            str=str+'&';
        }
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                str[index]=str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                str[index]=str1[i-1];
                i--;
                index--;
            }
            else
            {
                str[index]=str2[j-1];
                j--;
                index--;
            }
        }
        while(i>0)
        {
            str[index]=str1[i-1];
            i--;
            index--;
        }
        while(j>0)
        {
            str[index]=str2[j-1];
            j--;
            index--;
        }
        return str;
    }
};