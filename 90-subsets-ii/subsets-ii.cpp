class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        int sub=1<<n;
        set<vector<int>>st;
        //to check duplicates
        //without sorting subsets like [1,2] and [2,1] will not treat as duplicates  
        sort(nums.begin(),nums.end());
        for(int i=0;i<sub;i++)
        {
            vector<int>list;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))//check ith bit is set or not
                {
                    list.push_back(nums[j]);
                }
            }
            st.insert(list);//to store unique subsets
        }
        for(auto it:st)
        {
            result.push_back(it);//convert set to vector
        }
        return result;
    }
};