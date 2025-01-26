class Solution {
public:
    int top(vector<int>&dp,int n)
    {
        if(n==0||n==1)
        {
            return 1;
        }
        if(dp[n]!=0)
        {
            return dp[n];
        }
        return dp[n]=top(dp,n-1)+top(dp,n-2);
    }
    int climbStairs(int n) {
       vector<int>dp(n+1,0);
       return top(dp,n);
    }
};