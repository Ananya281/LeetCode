class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int element1=0;
        int element2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(count1==0&&nums[i]!=element2)
            {
                count1++;
                element1=nums[i];
            }
            else if(count2==0&&nums[i]!=element1)
            {
                count2++;
                element2=nums[i];
            }
            else if(element1==nums[i])
            {
                count1++;
            }
            else if(element2==nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++)
        {
            if(element1==nums[i])
            {
                count1++;
            }
            else if(element2==nums[i])
            {
                count2++;
            }
        }
        vector<int>result;
        if(count1>(n/3))
        {
            result.push_back(element1);
        }
        if(count2>(n/3))
        {
            result.push_back(element2);
        }
        return result;
    }
};