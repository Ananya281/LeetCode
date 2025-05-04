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
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return minicut(1,c,dp,cuts);
    }
};