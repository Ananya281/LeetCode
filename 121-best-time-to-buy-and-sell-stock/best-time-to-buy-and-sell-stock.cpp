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
        return dp[i][j]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return memo(0,0,prices,dp);
    }
};