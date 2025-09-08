class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int longest=1;
        for(auto it:st)
        {
            int ele=it;
            if(st.find(ele-1)==st.end())
            {
                int count=1;
                int x=ele;
                while(st.find(x+1)!=st.end())
                {
                    count++;
                    x++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};