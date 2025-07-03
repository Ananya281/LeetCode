class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int n=nums.size();
     map<int,int>mpp;
     mpp[0]=1;
     int count=0;
     int sum=0;
     for(int i=0;i<n;i++)
     {
        sum=sum+nums[i];
        int rem=sum-k;
        if(mpp.find(rem)!=mpp.end())
        {
            count=count+mpp[rem];
        }
        mpp[sum]=mpp[sum]+1;
     }   
     return count;
    }
};