class Solution {
public:
int memo(int ind,vector<int>&dp)
{
    if(ind==0)
    {
        return 1;
    }
    if(ind==1)
    {
        return 1;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int ones=memo(ind-1,dp);
    int twoe=memo(ind-2,dp);
    return dp[ind]=ones+twoe;
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return memo(n,dp);
    }
};