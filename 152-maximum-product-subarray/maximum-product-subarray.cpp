class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int prod=1;
            for(int j=i;j<n;j++)
            {
                prod=prod*nums[j];
                if(prod>ans)
                {
                    ans=prod;
                }
            }
            if(prod>ans)
            {
                ans=prod;
            }
        }
        return ans;
    }
};