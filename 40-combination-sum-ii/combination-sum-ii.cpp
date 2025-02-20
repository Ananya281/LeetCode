class Solution {
public:
    void find(int ind,int target,vector<int>&candidates,vector<int>&ans,vector<vector<int>>&result)
    {
        int n=candidates.size();
        if(target==0)
        {
            result.push_back(ans);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(i>ind && candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(candidates[i]>target)
            {
                break;
            }
            ans.push_back(candidates[i]);
            find(i+1,target-candidates[i],candidates,ans,result);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        vector<vector<int>>result;
        find(0,target,candidates,ans,result);
        return result;
    }
};