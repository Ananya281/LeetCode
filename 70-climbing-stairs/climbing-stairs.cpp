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
    int space(int n)
    {
        int prev2=1;
        int prev1=1;
        int curr;
        if(n==0||n==1)
        {
            return 1;
        }
        for(int i=2;i<=n;i++)
        {
            curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return memo(dp,n);  
        // return tabu(dp,n);
        return space(n);      
    }
};