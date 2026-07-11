class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};


// 0 low-1  low mid-1  remaining

// 0 0 1 1 2 2                  


// 0 0 2 1 1 2
//     l        h 
//     m

// start -- low   kuch kuch  high -- end