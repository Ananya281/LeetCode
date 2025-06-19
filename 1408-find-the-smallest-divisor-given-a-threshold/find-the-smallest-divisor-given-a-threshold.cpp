class Solution {
public:
    int func(vector<int>&nums,int divisor)
    {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total+ceil((double)nums[i]/divisor);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
        }
        int ans=maxi;
        int low=1;
        int high=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int sum=func(nums,mid);
            if(sum<=threshold)
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