class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result(n,-1);
        if(n<(2*k+1))
        {
            return result;
        }
        vector<long long>prefixsum;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            prefixsum.push_back(sum);
        }
        for(int i=k;i<n-k;i++)
        {
            int leftindex=i-k;
            int rightindex=i+k;
            if(leftindex>0)
            {
                result[i]=((prefixsum[rightindex]-prefixsum[leftindex-1])/((2*k)+1));
            }
            else
            {
                result[i]=((prefixsum[rightindex])/((2*k)+1));
            }
        }
        return result;
    }
};