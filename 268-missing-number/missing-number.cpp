class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<=n;i++)
        {
            mpp[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second==0)
            {
                return it.first;
            }
        }
        return -1;
    }
};