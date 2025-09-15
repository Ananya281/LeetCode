class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int minlength=INT_MAX;
        while(j<n)
        {
            sum=sum+nums[j];
            while(sum>=target)
            {
                minlength=min(minlength,j-i+1);
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
        if(minlength==INT_MAX)
        {
            return 0;
        }
        return minlength;
    }
};