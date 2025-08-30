class Solution {
public:
    double total(int mid,vector<int>&dist)
    {
        double time=0;
        for(int i=0;i<dist.size();i++)
        {
            if(i==dist.size()-1)
            {
                time=time+(double)dist[i]/mid;
            }
            else
            {
                time=time+ceil((double)dist[i]/mid);
            }
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int low=1;
        int high=1e7;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(total(mid,dist)<=hour)
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