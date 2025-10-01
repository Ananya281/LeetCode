class Solution {
public:
    int memo(int i,int j,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(j==2)
        {
            return 0;
        }
        int n=prices.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int maxi=INT_MIN;
        if(j==0)
        {
            maxi=max(-prices[i]+memo(i+1,1,prices,dp),memo(i+1,0,prices,dp));
        }
        if(j==1)
        {
            maxi=max(prices[i]+memo(i+1,2,prices,dp),memo(i+1,1,prices,dp));
        }
        return maxi;
    }
    int tabu(int n,vector<int>&prices,vector<vector<int>>&dp)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][2]=0;
        }
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n][2]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                int maxi=INT_MIN;
                if(j==0)
                {
                    maxi=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                if(j==1)
                {
                    maxi=max(prices[i]+dp[i+1][2],dp[i+1][1]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[0][0];
    }
    int space(int n,vector<int>&prices,vector<int>&dp)
    {
        dp[2]=0;
        dp[1]=0;
        dp[0]=0;
        for(int i=n-1;i>=0;i--)
        {
            vector<int>temp(3,-1);
            temp[2]=0;
            for(int j=0;j<2;j++)
            {
                int maxi=INT_MIN;
                if(j==0)
                {
                    maxi=max(-prices[i]+dp[1],dp[0]);
                }
                if(j==1)
                {
                    maxi=max(prices[i]+dp[2],dp[1]);
                }
                temp[j]=maxi;
            }
            dp=temp;
        }
        return dp[0];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(3,-1));
        // return memo(0,0,prices,dp);
        // vector<vector<int>>dp(n+1,vector<int>(3,-1));
        // return tabu(n,prices,dp);
        vector<int>dp(3,-1);
        return space(n,prices,dp);
    }
};