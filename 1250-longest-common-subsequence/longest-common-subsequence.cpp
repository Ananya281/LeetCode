class Solution {
public:
    int memo(int i,int j,string text1,string text2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i]==text2[j])
        {
            return 1+memo(i-1,j-1,text1,text2,dp);
        }
        int up=memo(i-1,j,text1,text2,dp);
        int left=memo(i,j-1,text1,text2,dp);
        return dp[i][j]=max(up,left);
    }
    int tabu(int n,int m,string text1,string text2,vector<vector<int>>&dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
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
    int space(int n,int m,string text1,string text2,vector<int>&dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            vector<int>temp(m+1,-1);
            temp[0]=0;
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    temp[j]=1+dp[j-1];
                }
                else
                {
                    int up=dp[j];
                    int left=temp[j-1];
                    temp[j]=max(up,left);
                }
            }
            dp=temp;
        }
        return dp[m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memo(n-1,m-1,text1,text2,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans= tabu(n,m,text1,text2,dp);
        string str="";
        for(int i=0;i<ans;i++)
        {
            str=str+'&';
        }
        int i=n;
        int j=m;
        int index=ans-1;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                str[index]=text1[i-1];
                i--;
                j--;
                index--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        cout<<str;
        return ans;
        // vector<int>dp(m+1,-1);
        // return space(n,m,text1,text2,dp);
    }
};