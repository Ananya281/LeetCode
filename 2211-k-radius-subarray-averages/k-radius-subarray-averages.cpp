class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)
        {
            return nums;
        }
        vector<int>result(n,-1);
        if(n<(2*k+1))
        {
            return result;
        }
        vector<long long>prefix(n,-1);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=k;i<=n-k-1;i++)
        {
            int leftidx=i-k;
            int rightidx=i+k;
            long long sum=prefix[i+k];
            if(leftidx>0)
            {
                sum=sum-prefix[i-k-1];
            }
            int avg=sum/(2*k+1);
            result[i]=avg;
        }
        return result;
    }
};