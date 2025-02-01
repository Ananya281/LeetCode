class Solution {
public:
    int memo(vector<int>&dp,int n,vector<int>&nums)
    {
        if(n==0)
        {
            return nums[n];
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int pick=nums[n]+memo(dp,n-2,nums);
        int nonpick=memo(dp,n-1,nums);
        dp[n]=max(pick,nonpick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans1=memo(dp,n-1,nums);
        return ans1;
    }
};