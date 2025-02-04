class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        for(int start=0;start<n;start++)
        {
            if(start>reach)
            {
                return false;
            }
            reach=max(reach,nums[start]+start);
        }
        return true;
    }
};