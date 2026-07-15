class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>numindex;
        for(int i=0;i<n;i++)
        {
            numindex.push_back({nums[i],i});
        }
        sort(numindex.begin(),numindex.end());
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int sum=numindex[left].first+numindex[right].first;
            if(sum==target)
            {
                return {numindex[left].second,numindex[right].second};
            }
            else if(sum<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {-1,-1};
    }
};