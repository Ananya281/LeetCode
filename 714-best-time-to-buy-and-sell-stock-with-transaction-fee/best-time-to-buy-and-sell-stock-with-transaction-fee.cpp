class Solution {
public:
    int memo(int i, int buy, vector<vector<int>>&dp,vector<int>&prices,int fee)
    {
        int n=prices.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }
        int profit=INT_MIN;
        if(buy==1)
        {
            profit=max(-prices[i]+memo(i+1,0,dp,prices,fee),memo(i+1,1,dp,prices,fee));
        }
        else
        {
            profit=max(prices[i]+memo(i+1,1,dp,prices,fee)-fee,memo(i+1,0,dp,prices,fee));
        }
        return dp[i][buy]=profit;
    }
    int tabu(int n, vector<vector<int>>&dp,vector<int>&prices,int fee)
    {
        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n+1][0] = 0;
        dp[n+1][1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                int profit=INT_MIN;
                if(j==1)
                {
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit=max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
    }
    int space(int n,vector<int>&dp,vector<int>&prices,int fee)
    {
        for(int i=n-1;i>=0;i--)
        {
            vector<int>temp(2,0);
            for(int j=0;j<2;j++)
            {
                int profit=INT_MIN;
                if(j==1)
                {
                    profit=max(-prices[i]+dp[0],dp[1]);
                }
                else
                {
                    profit=max(prices[i]-fee+dp[1],dp[0]);
                }
                temp[j]=profit;
            }
            dp=temp;
        }
        return dp[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return memo(0,1,dp,prices,fee);
        // vector<vector<int>>dp(n+2,vector<int>(2,-1));
        // return tabu(n,dp,prices,fee);
        vector<int>dp(2,0);
        return space(n,dp,prices,fee);
    }
};