class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor1=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            xor1=xor1^nums[i];
        }
        long long rightmost=xor1^(xor1&(xor1-1));
        int a=0;
        int b=0;
        for(auto it:nums)
        {
            if((rightmost&it)==0)
            {
                a=a^it;
            }
            else
            {
                b=b^it;
            }
        }
        return {a,b};
    }
};