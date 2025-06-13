class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total+nums[i];
        }
        int cs=0;
        for(int i=0;i<n;i++)
        {
            if(cs==(total-cs-nums[i]))
            {
                return i;
            }
            cs=cs+nums[i];
        }
        return -1;
    }
};