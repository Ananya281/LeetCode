class Solution {
public:
    int tabu(int n,vector<int>&dp)
    {
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int once=dp[i-1];
            int twoe=dp[i-2];
            dp[i]=once+twoe;
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return tabu(n,dp);
    }
};