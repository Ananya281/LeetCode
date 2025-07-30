class Solution {
public:
    int memo(int i, int state, vector<vector<int>>& dp, vector<int>& prices) {
        if (i == prices.size() || state == 2) return 0; // done with transaction
        if (dp[i][state] != -1) return dp[i][state];

        int profit = 0;
        if (state == 0) {
            // Can buy or skip
            profit = max(-prices[i] + memo(i + 1, 1, dp, prices),  // buy
                         memo(i + 1, 0, dp, prices));             // skip
        } else if (state == 1) {
            // Can sell or skip
            profit = max(prices[i] + memo(i + 1, 2, dp, prices),  // sell
                         memo(i + 1, 1, dp, prices));             // skip
        }

        return dp[i][state] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1)); // 3 states: buy, sell, done
        return memo(0, 0, dp, prices); // start with option to buy
    }
};
