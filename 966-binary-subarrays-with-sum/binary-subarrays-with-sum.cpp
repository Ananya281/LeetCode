class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        map<int,int>mpp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(sum==goal)
            {
                count=count+1;
            }
            int rem=sum-goal;
            if(mpp.find(rem)!=mpp.end())
            {
                count=count+mpp[rem];
            }
            mpp[sum]++;
        }
        return count;
    }
};