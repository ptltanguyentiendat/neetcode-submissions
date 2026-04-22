class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /// dp[i][0]: xét i món đồ đầu tiên, và hiện tại có đồng xu
        /// dp[i][1]: xét i món đồ đầu tiên, và hiện tại không có đồng xu
        /// dp[i][2]: vừa bán thằng i
        int n = prices.size();
        vector<vector<int>> dp(n + 5, vector<int>(3, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for(int i = 1; i < n; i++){
            /// Nếu mua thằng i
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);

            dp[i][1] =  dp[i - 1][0] + prices[i];

            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
