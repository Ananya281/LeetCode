class Solution {
public:
    void func(int ind,vector<int>&nums,vector<vector<int>>&result,vector<int>&temp)
    {
        if(ind==nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(ind+1,nums,result,temp);
        temp.pop_back();
        func(ind+1,nums,result,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        vector<int>temp;
        func(0,nums,result,temp);
        return result;
    }
};