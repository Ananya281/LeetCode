class Solution {
public:
    int digitsum(int num)
    {
        int rem=0;
        int sum=0;
        while(num>0)
        {
            rem=num%10;
            num=num/10;
            sum=sum+rem;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        // priority_queue<int>pq;
        int maxsum=-1;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int sum=digitsum(num);
            if(mpp.find(sum)!=mpp.end())
            {
                // pq.push(nums[i]+nums[mpp[sum]]);
                maxsum=max(maxsum,nums[i]+nums[mpp[sum]]);
                // mpp[sum]=max(mpp[sum],i);
                if(nums[i]>nums[mpp[sum]])
                {
                    mpp[sum]=i;
                }
            }
            else
            {
                mpp[sum]=i;
            }
        }
        return maxsum;
    }
};