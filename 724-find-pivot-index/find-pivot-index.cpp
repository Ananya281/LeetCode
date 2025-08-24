class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            leftsum[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum=sum+nums[i];
            rightsum[i]=sum;
        }
        for(int i=0;i<n;i++)
        {
            if(leftsum[i]==rightsum[i])
            {
                return i;
            }
        }
        return -1;
    }
};