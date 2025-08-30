class Solution {
public:
    int func(vector<int>&bloomDay,int day,int m,int k)
    {
        int n=bloomDay.size();
        int count=0;
        int bloom=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=day)
            {
                count++;
                if(count==k)
                {
                    bloom++;
                    count=0;
                }
            }
            else
            {
                count=0;
            }
        }
        return bloom;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<1LL*m*k)
        {
            return -1;
        }
        int mini=bloomDay[0];
        int maxi=bloomDay[0];
        for(int i=0;i<n;i++)
        {
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int ans=maxi;
        int low=mini;
        int high=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int bloom=func(bloomDay,mid,m,k);//no. of bouquets
            if(bloom>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};