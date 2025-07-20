class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int pre=1;
        int suff=1;
        int maxprod=0;
        for(int i=0;i<n;i++)
        {
            if(pre==0)
            {
                pre=1;
            }
            if(suff==0)
            {
                suff=1;
            }
            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            maxprod=max({maxprod,pre,suff});
        }
        return maxprod;
    }
};