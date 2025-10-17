class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&curr,vector<vector<int>>&result)
    {
        int n=nums.size();
        if(ind==n)
        {
            result.push_back(curr);
            return;
        }
        solve(ind+1,nums,curr,result);
        curr.push_back(nums[ind]);
        solve(ind+1,nums,curr,result);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        vector<int>curr;
        solve(0,nums,curr,result);
        return result;
    }
};