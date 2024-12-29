class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        int sub=1<<n;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<sub;i++)
        {
            vector<int>list;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    list.push_back(nums[j]);
                }
            }
            st.insert(list);
        }
        for(auto it:st)
        {
            result.push_back(it);
        }
        return result;
    }
};