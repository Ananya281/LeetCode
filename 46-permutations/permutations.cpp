class Solution {
public:
    void recurr(vector<vector<int>>&result,vector<int>&nums,int i)
    {
        int n=nums.size();
        if(i==n)
        {
            result.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++)
        {
            swap(nums[i],nums[j]);
            recurr(result,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        recurr(result,nums,0);
        return result;
    }
};