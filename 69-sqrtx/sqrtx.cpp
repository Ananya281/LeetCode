class Solution {
public:
    int mySqrt(int x) {
        long long int low=0;
        long long int high=x;
        long long int ans=-1;
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            long long int sq=(mid*mid);
            if(sq<=x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return (int)ans;
    }
};

// x ka root=mid
// mid*mid=sq
// sq<=x then shifts low and if not shifts high