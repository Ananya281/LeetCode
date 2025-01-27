class Solution {
public:
int space(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    int prev=1;
    int prev2=1;
    int curr;
    for(int i=2;i<=n;i++)
    {
        curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return curr;
}
int tabu(vector<int>&dp,int n)
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int racoon(vector<int>&dp,int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=racoon(dp,n-1)+racoon(dp,n-2);
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // int r=racoon(dp,n);
        // int t=tabu(dp,n);
        int s=space(n);
        return s;
    }
};
// 0 1 2 3 4 5 6 
// 0 1 1
// 0=prev2 1=prev 2=curr