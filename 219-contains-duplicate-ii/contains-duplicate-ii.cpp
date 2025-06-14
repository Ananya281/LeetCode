class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            if(mpp.find(num)!=mpp.end() && abs((i-mpp[num])<=k))
            {
                return true;
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};