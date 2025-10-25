class Solution {
public:
    void recursion(int i, vector<vector<int>>&result,vector<int>&temp,vector<int>&candidates,int target)
    {
        int n=candidates.size();
            if(target==0)
            {
                result.push_back(temp);
                return;
            }
            if(i==n)
            {
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


// Order of base cases matters, because:

// You want to check for a valid combination (target == 0) before stopping recursion due to i == n.

// If target == 0 happens at the same time as i == n, and your code checks i == n first, it will return before adding the valid combination.