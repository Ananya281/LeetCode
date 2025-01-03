class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>presum(n);
        long long sump=0;
        for(int i=0;i<n;i++)
        {
            sump=sump+nums[i];
            presum[i]=sump;
        }
        vector<long long>postsum(n);
        long long sume=0;
        for(int i=n-1;i>=0;i--)
        {
            sume=sume+nums[i];
            postsum[i]=sume;
        } 
        int p=0;
        int q=1;
        int count=0;
        while(p<n&&q<n)
        {
            if(presum[p]>=postsum[q])
            {
                count++;
            }
            p++;
            q++;
        }
        return count;
    }
};