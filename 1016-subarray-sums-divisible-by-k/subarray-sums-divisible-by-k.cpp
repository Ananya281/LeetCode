class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        mpp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            int mod=sum%k;
            if(mod<0)
            {
                mod=mod+k;
            }
            if(mpp.find(mod)!=mpp.end())
            {
                count=count+mpp[mod];
                mpp[mod]++;
            }
            else
            {
                mpp[mod]=1;
            }
        }
        return count;
    }
};