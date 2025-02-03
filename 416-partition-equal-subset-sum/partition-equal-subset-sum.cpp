class Solution {
public:
    bool memo(int ind,int target,vector<vector<int>>&dp,vector<int>&nums)
    {
        if(target==0)
        {
            return true;
        }
        if(ind==0)
        {
            return nums[0]==target;
        }
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        bool nontake=memo(ind-1,target,dp,nums);
        bool take=false;
        if(nums[ind]<=target)
        {
            take=memo(ind-1,target-nums[ind],dp,nums);
        }
        return dp[ind][target]=take||nontake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total+nums[i];
        }
        if(total%2!=0)
        {
            return false;
        }
        int sum=total/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return memo(n-1,sum,dp,nums);
    }
};