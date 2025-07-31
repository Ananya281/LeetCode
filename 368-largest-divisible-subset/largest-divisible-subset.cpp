class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]+1>dp[i] && nums[i]%nums[j]==0)
                    {
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                }
            }
        }
        int index=-1;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                index=i;
            }
        }
        vector<int>result;
        result.push_back(nums[index]);
        while(parent[index]!=-1)
        {
            result.push_back(nums[parent[index]]);
            index=parent[index];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};