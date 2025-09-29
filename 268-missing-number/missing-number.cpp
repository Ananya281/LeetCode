class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]=i;
        }
        for(int i=0;i<=n;i++)
        {
            if(mpp.find(i)==mpp.end())
            {
                return i;
            }
        }
        return -1;
    }
};