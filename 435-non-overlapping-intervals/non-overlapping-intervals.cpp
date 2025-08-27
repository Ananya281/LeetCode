class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        int i=0;
        int j=1;
        while(j<n)
        {
            vector<int>curr=intervals[i];
            vector<int>nextint=intervals[j];
            int cs=curr[0];
            int ce=curr[1];
            int ns=nextint[0];
            int ne=nextint[1];
            if(ce<=ns)//no overlapping
            {
                i=j;
                j++;
            }
            else if(ce<=ne)//overlapping
            {
                count++;
                j++;
            }
            else if(ce>ne)
            {
                i=j;
                j++;
                count++;
            }
        }
        return count;
    }
};