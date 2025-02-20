class Solution {
public:
    void find(int ind,int k,int target,vector<int>&ans,vector<vector<int>>&result)
    {
        if(k==0 && target==0)
        {
            result.push_back(ans);
            return;
        }
        if(k==0 || target==0)
        {
            return;
        }
        for(int i=ind;i<=9;i++)
        {
            ans.push_back(i);
            find(i+1,k-1,target-i,ans,result);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>ans;
        find(1,k,n,ans,result);
        return result;
    }
};