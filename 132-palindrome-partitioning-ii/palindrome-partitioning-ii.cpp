class Solution {
public:
    bool ispallindrom(int i,int j,string&s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int memo(int i, int n, string& s, vector<int>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(ispallindrom(i,j,s))//start,end,string
            {
                int cost=1+memo(j+1,n,s,dp);
                mini=min(mini,cost);
            }
        }
        dp[i]=mini;
        return dp[i];
    }
    int tabu(int n,vector<int>&dp,string &s)
    {
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(ispallindrom(i,j,s))
                {
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
            dp[i]=mini;
        }
        return dp[0];
    }
    int minCut(string s) {
        int n = s.length();
        // vector<int>dp(n,-1);
        // return memo(0,n,s,dp)-1;
        vector<int>dp(n+1,-1);
        return tabu(n,dp,s)-1;
    }
};