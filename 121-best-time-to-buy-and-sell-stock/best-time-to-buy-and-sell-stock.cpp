class Solution {
public:
    int memo(int i,int state,vector<vector<int>>&dp,vector<int>&prices)
    {
        int n=prices.size();
        if(i==n || state==2)
        {
            return 0;
        }
        if(dp[i][state]!=-1)
        {
            return dp[i][state];
        }
        int profit=INT_MIN;
        if(state==0)
        {
            profit=max(-prices[i]+memo(i+1,1,dp,prices),memo(i+1,0,dp,prices));
        }
        else if(state==1)
        {
            profit=max(prices[i]+memo(i+1,2,dp,prices),memo(i+1,1,dp,prices));
        }
        return dp[i][state]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));//buy,sell,done
        return memo(0,0,dp,prices);
    }
};