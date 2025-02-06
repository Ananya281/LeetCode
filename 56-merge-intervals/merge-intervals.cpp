class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(int i=1;i<n;i++)
        {
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s<=temp[1])
            {
                temp[1]=max(e,temp[1]);
            }
            else
            {
                result.push_back(temp);
                temp=intervals[i];
            }
        }
        result.push_back(temp);
        return result;
    }
};