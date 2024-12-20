class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1)
        {
            return 0;
        }
        int left=0;
        int right=0;
        int count=0;
        int prod=1;
        while(right<n)
        {
            prod=prod*nums[right];
            while(prod>=k&&left<=right)
            {
                prod=prod/nums[left];
                left++;
            }
            count=count+(right-left+1);
            right++;
        }
        return count;
    }
};