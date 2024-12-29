class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        int sub=1<<n;
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
            result.push_back(list);
        }
        return result;
    }
};