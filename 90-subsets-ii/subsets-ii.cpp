class Solution {
public:
//using bit manipulation
//need set for storing unique
//then after completion pushback all the elements from stack to vector
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int subsets=1<<n;
        set<vector<int>>st;
        for(int i=0;i<subsets;i++)
        {
            vector<int>subset;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    subset.push_back(nums[j]);
                }
            }
            st.insert(subset);
        }
        vector<vector<int>>result(st.begin(),st.end());
        return result;   
    }
};