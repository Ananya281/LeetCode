class Solution {
public:
    void recurr(int i,vector<vector<int>>&result,vector<int>&temp,vector<int>&candidates,int target)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                result.push_back(temp);
            }
            return;
        }
        recurr(i+1,result,temp,candidates,target);
        if(candidates[i]<=target)
        {
            temp.push_back(candidates[i]);
            recurr(i,result,temp,candidates,target-candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>result;
        vector<int>temp;
        recurr(0,result,temp,candidates,target);
        return result;
    }
};