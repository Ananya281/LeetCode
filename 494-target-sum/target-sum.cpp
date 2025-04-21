class Solution {
public:
    int memo(int i,int target,vector<vector<int>>&dp,vector<int>&nums)
    {
        if(i==0)
        {
            if(nums[0]==0 && target==0)
            {
                return 2;
            }
            if(target == 0 || nums[0] == target)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }
        int nonpick=memo(i-1,target,dp,nums);
        int pick=0;
        if(nums[i]<=target)
        {
            pick=memo(i-1,target-nums[i],dp,nums);
        }
        dp[i][target]=pick+nonpick;
        return dp[i][target];
    }
    int tabu(int n,int target,vector<vector<int>>&dp,vector<int>&nums)
    {
        if(nums[0]==0)
        {
            dp[0][0]=2;
        }
        else
        {
            dp[0][0]=1;
        }
        if(nums[0]!=0 && nums[0]<=target)
        {
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                int nonpick=dp[i-1][j];
                int pick=0;
                if(nums[i]<=j)
                {
                    pick=dp[i-1][j-nums[i]];
                }
                dp[i][j]=pick+nonpick;
            }
        }
        return dp[n-1][target];
    }
    int space(int n,int target,vector<int>&prev,vector<int>&nums)
    {
        if(nums[0]==0)
        {
            prev[0]=2;
        }
        else
        {
            prev[0]=1;
        }
        if(nums[0]!=0 && nums[0]<=target)
        {
            prev[nums[0]]=1;
        }
        for(int i=1;i<n;i++)
        {
            vector<int>temp(target+1,0);
            for(int j=0;j<=target;j++)
            {
                int nonpick=prev[j];
                int pick=0;
                if(nums[i]<=j)
                {
                    pick=prev[j-nums[i]];
                }
                temp[j]=pick+nonpick;
            }
            prev=temp;
        }
        return prev[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total+nums[i];
        }
        int s2=(total-target)/2;
        if((total-target)<0 || (total-target)%2==1)
        {
            return 0;
        }
        // vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        // return memo(n-1,s2,dp,nums);
        // vector<vector<int>>dp(n,vector<int>(s2+1,0));
        // return tabu(n,s2,dp,nums);
        vector<int>dp(s2+1,0);
        return space(n,s2,dp,nums);
    }
};