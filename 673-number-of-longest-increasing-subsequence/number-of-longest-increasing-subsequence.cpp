class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        vector<int>count(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[j]+1>dp[i])
                {
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else if(nums[j]<nums[i] && dp[j]+1==dp[i])
                {
                    count[i]=count[i]+count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                cnt=cnt+count[i];
            }
        }
        return cnt;
    }
};