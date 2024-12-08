class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        map<int,int>mpp;
        int presum=0;
        int count=0;
        mpp[0]=1;
        for(int i=0;i<n;i++)
        {
            presum=presum+nums[i];
            int rem=presum-goal;
            count=count+mpp[rem];
            mpp[presum]++;
        }
        return count;
    }
};