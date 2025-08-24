class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1,0);
        vector<int>result(2,-1);
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(freq[i]==2)
            {
                result[0]=i;
            }
            if(freq[i]==0)
            {
                result[1]=i;
            }
        }
        return result;
    }
};