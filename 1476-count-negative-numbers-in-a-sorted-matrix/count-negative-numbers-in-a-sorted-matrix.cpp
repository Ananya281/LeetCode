class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int low=0;
            int high=m-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(grid[i][mid]>=0)
                {
                    low=mid+1;
                }
                else if(grid[i][mid]<0)
                {
                    count=count+high-mid+1;
                    high=mid-1;
                }
            }
        }
        return count;
    }
};