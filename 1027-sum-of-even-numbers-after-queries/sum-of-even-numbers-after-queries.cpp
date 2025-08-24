class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                sum=sum+nums[i];
            }
        }
        int m=queries.size();
        vector<int>result;
        for(int j=0;j<m;j++)
        {
            int num=queries[j][0];
            int ind=queries[j][1];
            if(nums[ind]%2==0)
            {
                sum=sum-nums[ind];
                if((nums[ind]+num)%2==0)
                {
                    sum=sum+nums[ind]+num;
                }
            }
            else
            {
                if((nums[ind]+num)%2==0)
                {
                    sum=sum+nums[ind]+num;
                }
            }
            nums[ind]=nums[ind]+num;
            result.push_back(sum);
        }
        return result;
    }
};