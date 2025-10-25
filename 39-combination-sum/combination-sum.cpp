class Solution {
public:
    void recursion(int i, vector<vector<int>>&result,vector<int>&temp,vector<int>&candidates,int target)
    {
        int n=candidates.size();

            if(i==n)
            {
                return;
            }
            if(target==0)
            {
                result.push_back(temp);
                return;
            }
        recursion(i+1,result,temp,candidates,target);//nonpick
        if(candidates[i]<=target)//pick
        {
            temp.push_back(candidates[i]);
            recursion(i,result,temp,candidates,target-candidates[i]);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>temp;
        int n=candidates.size();
        recursion(0,result,temp,candidates,target);
        return result;
    }
};