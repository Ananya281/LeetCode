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
    int tabu(int n,vector<vector<vector<int>>>&dp,vector<int>&prices)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                dp[n][i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j][0]=0;
            }
        }
        for(int i=n-1;i>=0;i--)//index
        {
            for(int j=0;j<2;j++)//state
            {
                for(int k=1;k<3;k++)//capacity
                {
                    int profit=INT_MIN;
                    if(j==0)
                    {
                        profit=max(-prices[i]+dp[i+1][1][k],dp[i+1][0][k]);
                    }
                    if(j==1)
                    {
                        profit=max(prices[i]+dp[i+1][0][k-1],dp[i+1][1][k]);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][0][2];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));//0,1,2 transactions
        // return memo(0,0,2,dp,prices);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return tabu(n,dp,prices);
    }
};

// buy=0
// sell=1