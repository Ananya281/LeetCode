class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        int subset=1<<n;//2^n n=3 8 subsets total
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
            result.push_back(ans);
        }
        return result;
    }
};

// (1 << j) → ek number jisme sirf j-th bit set hai.
// j=0 → 0001
// j=1 → 0010
// j=2 → 0100

// (i & (1<<j)) check karta hai: kya i ka j-th bit 1 hai?
// agar 1 hai → matlab subset me nums[j] lena hai.
// agar 0 hai → skip karna hai.

// i=5 binary=101
// j=0 (5&1<<0) = 101&001=1 true ans=[10]
// j=1 false skip
// j=2 (5&1<<2) = 101&100=4 true ans=[10,30] subset push into result vector