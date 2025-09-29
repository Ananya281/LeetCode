class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int n=nums.size();
        if(n==0)
        {
            return result;
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int rem=target-num;
            if(mpp.find(rem)!=mpp.end())
            {
                result.push_back(i);
                result.push_back(mpp[rem]);
                return result;
            }
            mpp[num]=i;
        }
        return result;
    }
};