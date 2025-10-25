class Solution {
public:
    void recursion(int i,vector<vector<int>>&result,vector<int>&temp,vector<int>&candidates,int target)
    {
        if(target==0)
        {
            result.push_back(temp);
            return;
        }
        for(int j=i;j<candidates.size();j++)
        {
            if(i!=j && candidates[j]==candidates[j-1])
            {
                continue;
            }
            if(candidates[j]>target)
            {
                break;
            }
            temp.push_back(candidates[j]);//pick
            recursion(j+1,result,temp,candidates,target-candidates[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>temp;
        recursion(0,result,temp,candidates,target);
        return result;
    }
};


// Without the if condition
// At the first recursion call (i = 0):
// j = 0 → pick 1
// j = 1 → pick 1 again (duplicate)

// Both 1s are identical, so the recursive calls will explore exactly the same subtree, generating duplicate combinations like:

// [1,2,5]
// [1,2,5]  ← duplicate


// With the condition
// When i = 0 and j = 1,
// we check:
// if (i != j && candidates[j] == candidates[j-1])

// → true (1 == 1) → skip this duplicate.

// So only the first occurrence of 1 is used to start recursion at that level.


// For sorted input:
// [1, 1, 2, 5, 6, 7, 10]

// At i = 0 (start of recursion):
// j = 0 → pick first 1 ✅
// j = 1 → second 1, but i != j and same as previous → skip ❌

// At i = 1 (deeper recursion):
// j = 1 → pick second 1 ✅ (allowed now, because it's in deeper recursion level
// This gives valid combinations like [1,1,6] but avoids duplicates like [1,2,5] appearing twice.


// Why i != j is important
// We only skip duplicates within the same recursion depth.
// When i == j, it means we’re picking the first element of this level — don’t skip.
// When i != j, it means we’re iterating further in the same level — skip duplicates.

// This ensures that duplicate numbers can still appear in deeper levels (like [1,1,6] is valid) but not as different branches starting from the same level.