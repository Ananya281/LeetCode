class Solution {
public: 
    int lowerbound(vector<int>&nums,int element)
    {
        int low=0;
        int high=nums.size();
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=element)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        result.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>result.back())
            {
                result.push_back(nums[i]);
            }
            else
            {
                int ind=lowerbound(result,nums[i]);
                result[ind]=nums[i];
            }
        }   
        return result.size();
    }
};