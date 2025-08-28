class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        int currmax=0;
        int maxsum=INT_MIN;
        int currmin=0;
        int minsum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            currmax=max(nums[i],currmax+nums[i]);
            maxsum=max(maxsum,currmax);
            currmin=min(nums[i],currmin+nums[i]);
            minsum=min(minsum,currmin);
            total=total+nums[i];
            
        }
        if(maxsum<0)
        {
            return maxsum;
        }
        return max(maxsum,total-minsum);
    }
};