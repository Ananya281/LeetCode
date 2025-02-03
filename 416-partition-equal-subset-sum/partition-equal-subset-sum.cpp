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
    bool tabu(int n,int target,vector<vector<bool>>&dp,vector<int>&nums)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=target)
        {
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int k=1;k<=target;k++)
            {
                bool nontake=dp[i-1][k];
                bool take=false;
                if(nums[i]<=k)
                {
                    take=dp[i-1][k-nums[i]];
                }
                dp[i][k]=take||nontake;
            }
        }
        return dp[n-1][target];
    }
    int space(int n,int target,vector<int>&nums)
    {
        vector<bool>prev(target+1,false);
        vector<bool>curr(target+1,false);
        prev[0]=true;
        curr[0]=true;
        if(nums[0]<=target)
        {
            prev[nums[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int k=1;k<=target;k++)
            {
                bool nottake=prev[k];
                bool take=false;
                if(nums[i]<=k)
                {
                    take=prev[k-nums[i]];
                }
                curr[k]=take||nottake;
            }
            prev=curr;
        }
        return prev[target];
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
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return memo(n-1,sum,dp,nums);
        // vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        // return tabu(n,sum,dp,nums);
        return space(n,sum,nums);
    }
};