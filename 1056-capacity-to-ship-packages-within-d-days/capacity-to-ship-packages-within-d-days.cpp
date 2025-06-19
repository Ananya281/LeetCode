class Solution {
public:
    int func(vector<int>&weights,int capacity)
    {
        int n=weights.size();
        int days=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+weights[i]>capacity)
            {
                days++;
                sum=weights[i];
            }
            else
            {
                sum=sum+weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=weights[0];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(weights[i]>maxi)
            {
                maxi=weights[i];
            }
            sum=sum+weights[i];
        }
        int low=maxi;
        int high=sum;
        int ans=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int d=func(weights,mid);
            if(d<=days)
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