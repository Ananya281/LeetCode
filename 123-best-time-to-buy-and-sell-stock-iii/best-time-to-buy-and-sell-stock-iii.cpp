class Solution {
public:
    int memo(int i,int state,int capacity, vector<vector<vector<int>>>&dp,vector<int>&prices)
    {
        int n=prices.size();

        if(i==n || capacity==0)
        {
            return 0;
        }
        if(dp[i][state][capacity]!=-1)
        {
            return dp[i][state][capacity];
        }
        int profit=INT_MIN;
        if(state==0)
        {
            profit=max(-prices[i]+memo(i+1,1,capacity,dp,prices),memo(i+1,0,capacity,dp,prices));
        }
        else 
        {
            profit=max(prices[i]+memo(i+1,0,capacity-1,dp,prices),memo(i+1,1,capacity,dp,prices));
        }
        return dp[i][state][capacity]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return memo(0,0,2,dp,prices);
    }
};