class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int ansindex=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        long long leftsum=0;
        long long rightsum=0;
        long long ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            leftsum=leftsum+nums[i];
            rightsum=sum-leftsum;
            long long leftavg=leftsum/(i+1);
            long long rightavg;
            if(i==n-1)
            {
                rightavg=0;
            }
            else
            {
                rightavg=rightsum/(n-i-1);
            }
            long long diff=abs(leftavg-rightavg);
            if(diff<ans)
            {
                ans=diff;
                ansindex=i;
            }
        }
        return ansindex;
    }
};