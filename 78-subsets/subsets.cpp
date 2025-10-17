class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>result;
        int subsets=1<<n;//2^n total subsets
        for(int i=0;i<subsets;i++)
        {
            vector<int>ans;
            for(int j=0;j<n;j++)//check each bit of i
            {
                if(i&(1<<j))//if jth bit is 1, include nums[j]
                {
                    ans.push_back(nums[j]);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};

// 1<<j left shift operator
// means shift the number 1 left by j positions in binary
// j=0 1<<j 0001 --> 0001 becomes 1
// j=1 1<<j 0001 --> 0010 becomes 2
// j=2 1<<j 0001 --> 0100 becomes 4
// j=3 1<<j 0001 --> 1000 becomes 8
// 1<<j is like a flashlight, pointing only at jth bit

// i&(1<<j) bitwise AND
// 1&1=1
// 1&0=0
// 0&1=0
// 0&0=0
// if jth bit of i is 1, then AND with (1<<j) will be non-zero
// if jth bit of i is 0, then AND with (1<<j) will be zero
// flashlight sees 1, include that element
// if sees 0, skip it