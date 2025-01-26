class Solution {
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,0);
        int prev=1;
        int prev2=1;
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 1;
        }
        // dp[0]=1;
        // dp[1]=1;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};