class Solution {
public:
    int minicut(int i,int j,vector<vector<int>>&dp,vector<int>&cuts)
    {
        if(i>j)
        {
            return 0;
        }
        int mini=INT_MAX;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int ind=i;ind<=j;ind++)
        {
            int ans=cuts[j+1]-cuts[i-1]+minicut(i,ind-1,dp,cuts)+minicut(ind+1,j,dp,cuts);
            mini=min(mini,ans);
        }
        dp[i][j]=mini;
        return dp[i][j];
    }
    int tabu(int c,vector<vector<int>>&dp,vector<int>&cuts)
    {
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j)
                {
                    continue;
                }
                else
                {
                    int mini=INT_MAX;
                    for(int ind=i;ind<=j;ind++)
                    {
                        int ans=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                        mini=min(mini,ans);
                    }
                    dp[i][j]=mini;
                }
            }
        }
        return dp[1][c];
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        // return minicut(1,c,dp,cuts);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        return tabu(c,dp,cuts);
    }
};