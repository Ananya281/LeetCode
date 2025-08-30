class Solution {
public:
    long long getcost(int target,vector<int>&nums,vector<int>&cost)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+(1LL*abs(nums[i]-target))*cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
            if(nums[i]<mini)
            {
                mini=nums[i];
            }
        }
        int low=mini;
        int high=maxi;
        long long ans=getcost(nums[n-1],nums,cost);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long cost1=getcost(mid,nums,cost);
            long long cost2=getcost(mid+1,nums,cost);
            ans=min({ans,cost1,cost2});
            if(cost1<cost2)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};