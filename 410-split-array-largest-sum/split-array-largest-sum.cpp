class Solution {
public:
    bool can(vector<int>&nums,int k,int maxsum)
    {
        int currentsum=0;
        int n=nums.size();
        int split=1;
        for(int i=0;i<n;i++)
        {
            if(currentsum+nums[i]<=maxsum)
            {
                currentsum=currentsum+nums[i];
            }
            else
            {
                split++;
                currentsum=nums[i];
                if(split>k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            sum=sum+nums[i];
        }
        int low=maxi;
        int ans=maxi;
        int high=sum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(can(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};