class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int subset=1<<n;
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        set<vector<int>>st;
        for(int i=0;i<subset;i++)
        {
            vector<int>ans;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    ans.push_back(nums[j]);
                }
            }
            st.insert(ans);
        }
        for(auto it:st)
        {
            result.push_back(it);
        }
        return result;
    }
};