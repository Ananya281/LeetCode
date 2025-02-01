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
    int tabu(vector<int>&dp,int n,vector<int>&nums)
    {
        if(n==1)
        {
            return nums[0];
        }
        int prev=nums[0];
        int prev2=0;
        int curr;
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
            {
                pick=pick+prev2;
            }
            int nonpick=prev;
            curr=max(pick,nonpick);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // int ans1=memo(dp,n-1,nums);
        int ans2=tabu(dp,n,nums);
        return ans2;
    }
};