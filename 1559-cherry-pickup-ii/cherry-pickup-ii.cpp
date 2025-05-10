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
    int tabu(int n,int m,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[n-1][j1][j2]=grid[n-1][j1];
                }
                else
                {
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=INT_MIN;
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {
                            int ans=INT_MIN;
                            if(j1==j2)
                            {
                                ans=grid[i][j1];
                            }
                            else
                            {
                                ans=grid[i][j1]+grid[i][j2];
                            }
                            if(j1+d1<0 || j1+d1>=m || j2+d2<0 || j2+d2>=m)
                            {
                                ans=INT_MIN;
                            }
                            else
                            {
                                ans=ans+dp[i+1][j1+d1][j2+d2];
                            }
                            maxi=max(maxi,ans);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
    int space(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&grid)
    {
        vector<vector<int>>temp(m,vector<int>(m,-1));
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[j1][j2]=grid[n-1][j1];
                }
                else
                {
                    dp[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=INT_MIN;
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {
                            int ans=INT_MIN;
                            if(j1==j2)
                            {
                                ans=grid[i][j1];
                            }
                            else
                            {
                                ans=grid[i][j1]+grid[i][j2];
                            }
                            if(j1+d1<0 || j1+d1>=m || j2+d2<0 || j2+d2>=m)
                            {
                                ans=INT_MIN;
                            }
                            else
                            {
                                ans=ans+dp[j1+d1][j2+d2];
                            }
                            maxi=max(maxi,ans);
                        }
                    }
                    temp[j1][j2]=maxi;
                }
            }
            dp=temp;
        }
        return dp[0][m-1];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // return memo(0,0,m-1,dp,grid);
        return tabu(n,m,dp,grid);
    }
};