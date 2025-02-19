class Solution {
public:
    void find(int ind,int target,vector<int>&candidates,vector<int>&ans,vector<vector<int>>&result)
    {
        int n=candidates.size();
        if(ind==n)
        {
            if(target==0)
            {
                result.push_back(ans);
            }
            return;
        }
        if(target>=candidates[ind])
        {
            ans.push_back(candidates[ind]);
            find(ind,target-candidates[ind],candidates,ans,result);
            ans.pop_back();
        }
        find(ind+1,target,candidates,ans,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        find(0,target,candidates,ans,result);
        return result;
    }
};