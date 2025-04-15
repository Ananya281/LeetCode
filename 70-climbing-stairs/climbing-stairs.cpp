class Solution {
public:
    int memo(vector<int>&dp,int n)
    {
        if(n==0||n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n]=memo(dp,n-1)+memo(dp,n-2);
        return dp[n];
    }
    int tabu(vector<int>&dp,int n)
    {
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return memo(dp,n);  
        return tabu(dp,n);      
    }
};