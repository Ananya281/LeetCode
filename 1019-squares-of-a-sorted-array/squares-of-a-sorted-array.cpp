class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int index=n-1;
        vector<int>temp(n,-1);
        while(left<=right)
        {
            if(abs(nums[left])>=abs(nums[right]))
            {
                temp[index]=nums[left]*nums[left];
                left++;
            }
            else
            {
                temp[index]=nums[right]*nums[right];
                right--;
            }
            index--;
        }
        return temp;
    }
};