class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        while(k>1)
        {
            k--;
            int pivot=-1;
            for(int i=n-1;i>0;i--)
            {
                if(nums[i-1]<nums[i])
                {
                    pivot=i-1;
                    break;
                }
            }
            for(int i=n-1;i>pivot;i--)
            {
                if(nums[i]>nums[pivot])
                {
                    swap(nums[i],nums[pivot]);
                    break;
                }   
            }
            sort(nums.begin()+pivot+1,nums.end());
        }
        string str;
        for(int i=0;i<n;i++)
        {
            str=str+to_string(nums[i]);
        }
        return str;
    }
};