class Solution {
public:
    int tabu(int n,int m,vector<vector<int>>&dp,string str1,string str2)
    {
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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int len=tabu(n,m,dp,str1,str2);
        int l=n+m-len;
        string s="";
        for(int i=0;i<l;i++)
        {
            s=s+'*';
        }
        int index=l-1;
        int i=n;
        int j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s[index]=str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {

                s[index]=str1[i-1];
                index--;
                i--;
            }
            else
            {
                s[index]=str2[j-1];
                index--;
                j--;
            }
        }
        while(i>0)
        {
            s[index]=str1[i-1];
            index--;
            i--;
        }
        while(j>0)
        {
            s[index]=str2[j-1];
            index--;
            j--;
        }
        return s;
    }
};