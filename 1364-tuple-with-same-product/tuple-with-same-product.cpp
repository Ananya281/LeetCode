class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int prod=nums[i]*nums[j];
                count=count+(mpp[prod]*8);
                mpp[prod]++;
            }
        }
        return count;
    }
};