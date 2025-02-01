class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int i=1;
        while(i<n)
        {
            sum=nums[i]+nums[i-1];
            if(sum%2==0)
            {
                return false;
            }
            i++;
        }
        return true;
    }
};