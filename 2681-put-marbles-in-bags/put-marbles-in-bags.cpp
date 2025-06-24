class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>pairsum(n-1,0);
        for(int i=0;i<n-1;i++)
        {
            int sum=weights[i]+weights[i+1];
            pairsum[i]=sum;
        }
        int m=pairsum.size();
        long long mini=0;
        long long maxi=0;
        sort(pairsum.begin(),pairsum.end());
        for(int i=0;i<k-1;i++)
        {
            mini=mini+pairsum[i];
            maxi=maxi+pairsum[m-1-i];
        }
        return maxi-mini;
    }
};