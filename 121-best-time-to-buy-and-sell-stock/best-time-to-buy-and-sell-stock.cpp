class Solution {
public:
    int memo(int day,int state, vector<vector<int>>&dp,vector<int>&prices)
    {
        int n=prices.size();
        if(state==2)
        {
            return 0;
        }
        if(day==n)
        {
            return 0;
        }
        if(dp[day][state]!=-1)
        {
            return dp[day][state];
        }
        int maxi=INT_MIN;
        if(state==0)
        {
            maxi=max(-prices[day]+memo(day+1,1,dp,prices),memo(day+1,0,dp,prices));
        }
        else if(state==1)
        {
            maxi=max(prices[day]+memo(day+1,2,dp,prices),memo(day+1,1,dp,prices));
        }
        return dp[day][state]=maxi;
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(3,-1));//buy, sell, done
        // return memo(0,0,dp,prices);
        vector<vector<int>>dp(n+1,vector<int>(3,-1));//buy, sell, done
        return tabu(n,prices,dp);
    }
};
