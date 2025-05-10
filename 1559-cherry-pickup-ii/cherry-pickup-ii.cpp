class Solution {
public:
    int memo(int i,int j1,int j2,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(j1<0 || j1>=m || j2<0 || j2>=m)
        {
            return INT_MIN;
        }
        if(i==n-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int maxi=INT_MIN;
        for(int d1=-1;d1<=1;d1++)
        {
            for(int d2=-1;d2<=1;d2++)
            {
                int ans=INT_MIN;
                if(j1==j2)
                {
                    ans=grid[i][j1]+memo(i+1,j1+d1,j2+d2,dp,grid);
                }
                else
                {
                    ans=grid[i][j1]+grid[i][j2]+memo(i+1,j1+d1,j2+d2,dp,grid);
                }
                maxi=max(maxi,ans);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return memo(0,0,m-1,dp,grid);
    }
};