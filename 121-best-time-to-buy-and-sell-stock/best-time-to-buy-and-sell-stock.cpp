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
    int tabu(int n,vector<vector<int>>&dp,vector<int>&prices)
    {
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n][2]=0;
        for(int i=0;i<=n;i++)
        {
            dp[i][2]=0;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                int profit=INT_MIN;
                if(j==0)
                {
                    profit=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                else if(j==1)
                {
                    profit=max(prices[i]+dp[i+1][2],dp[i+1][1]);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][0];
    }
    int space(int n,vector<int>&dp,vector<int>&prices)
    {
        for(int i=n-1;i>=0;i--)
        {
            vector<int>temp(3,0);
            for(int j=0;j<2;j++)
            {
                int profit=INT_MIN;
                if(j==0)
                {
                    profit=max(-prices[i]+dp[1],dp[0]);
                }
                else if(j==1)
                {
                    profit=max(prices[i]+dp[2],dp[1]);
                }
                temp[j]=profit;
            }
            dp=temp;
        }
        return dp[0];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(3,-1));//buy,sell,done
        // return memo(0,0,dp,prices);
        // vector<vector<int>>dp(n+1,vector<int>(3,-1));//buy,sell,done
        // return tabu(n,dp,prices);
        vector<int>dp(3,0);
        return space(n,dp,prices);
    }
};