class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxcountup=1;
        int countup=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                countup++;
            }
            else
            {
                maxcountup=max(maxcountup,countup);
                cout<<maxcountup<<endl;
                countup=1;
            }
        }
        maxcountup=max(maxcountup,countup);
        int maxcountdown=1;
        int countdown=1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                countdown++;
            }
            else
            {
                maxcountdown=max(maxcountdown,countdown);
                cout<<maxcountdown<<endl;
                countdown=1;
            }
        }
        maxcountdown=max(maxcountdown,countdown);
        return max(maxcountup,maxcountdown);
    }
};