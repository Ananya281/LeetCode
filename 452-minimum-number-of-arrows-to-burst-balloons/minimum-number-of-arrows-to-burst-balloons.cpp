class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int count=1;
        int lastpoint=points[0][1];
        for(auto it:points)
        {
            if(it[0]>lastpoint)
            {
                count++;
                lastpoint=it[1];
            }
            lastpoint=min(it[1],lastpoint);
        }
        return count;
    }
};