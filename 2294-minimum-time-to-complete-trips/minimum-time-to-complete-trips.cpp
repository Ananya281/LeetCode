class Solution {
public:
    long long func(vector<int>& time,long long t)
    {
        int n=time.size();
        long long total=0;
        for(int i=0;i<n;i++)
        {
            total=total+t/time[i];
        }
        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        int mini=time[0];
        for(int i=0;i<n;i++)
        {
            if(time[i]<mini)
            {
                mini=time[i];
            }
        }
        long long low=1;
        long long high=(long long)mini*totalTrips;
        long long ans=high;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long total=func(time,mid);
            if(total>=totalTrips)
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