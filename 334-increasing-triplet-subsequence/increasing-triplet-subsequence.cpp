class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MAX;
        int second=INT_MAX;
        int third=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=first)
            {
                first=nums[i];
            }
            else if(nums[i]<=second && nums[i]>first)
            {
                second=nums[i];
            }
            else if(nums[i]<=third && nums[i]>second)
            {
                return true;
            }
        }
        return false;
    }
};