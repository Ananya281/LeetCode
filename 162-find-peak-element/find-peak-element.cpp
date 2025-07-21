class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        int low=1;
        int high=n-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            if(nums[mid]>nums[mid-1])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};

// 1 3 2 1
// low=1 high=2 mid=1 ans 

// 1 2 1 3 5 6 4
// low=1 high=5 mid=3 low=4 high=5 mid=4 low=5 high=5 mid=5 ans 