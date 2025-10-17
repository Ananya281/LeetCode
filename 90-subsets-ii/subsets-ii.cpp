class Solution {
public:
    void backtrack(int ind,vector<int>&nums,vector<int>&curr,vector<vector<int>>&result)
    {
        result.push_back(curr);//store current subset
        //must be called every time the recursive function is visited
        //because every recursive state itself represents a valid subset
        for(int j=ind;j<nums.size();j++)
        {
            if(j>ind && nums[j]==nums[j-1])//duplicate handling 
            {
                continue;
            }
            curr.push_back(nums[j]);
            backtrack(j+1,nums,curr,result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>curr;
        vector<vector<int>>result;
        backtrack(0,nums,curr,result);
        return result;
    }
};


// subsets II, Combination II, Permutations II
// if (j > i && nums[j] == nums[j - 1]) {
//     continue;
// }
// condition works only after sorting
// duplicate handling
// j>i not choosing first element of this level
// nums[j]==nums[j-1] this element is identical to the previous one
// then skip it, we already considered that number once in the decision level