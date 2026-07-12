class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ansstart=-1;
        int ansend=-1;
        int start=0;
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum==0)
            {
                start=i;
            }
            sum=sum+nums[i];
            if(sum>maxi)
            {
                maxi=sum;
                ansstart=start;
                ansend=i;
            }
            if(sum<0)
            {
                sum=0;
            }   
        }
        for(int i=ansstart;i<=ansend;i++)
        {
            cout<<nums[i]<<" ";
        }
        return maxi;
    }
};