class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int profit=0;
       int mini=prices[0];
       for(int i=1;i<n;i++)
       {
        int pro=prices[i]-mini;
        profit=max(profit,pro);
        mini=min(mini,prices[i]);
       }
       return profit;
    }
};