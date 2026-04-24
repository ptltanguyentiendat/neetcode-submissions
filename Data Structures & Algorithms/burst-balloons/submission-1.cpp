class Solution {
public:
    int maxCoins(vector<int>& nums) {
        /// dp[l][r]: MaxCoins trên [l, r];
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for(int i = 0; i < n; i++) newNums[i + 1] = nums[i];

        vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0));

        for(int l = n; l >= 1; l--){
            for(int r = l; r <= n; r++){
                for(int i = l; i <= r; i++){
                    int coins = newNums[l - 1] * newNums[i] * newNums[r + 1];
                    dp[l][r] = max(dp[l][r], dp[l][i - 1] + coins + dp[i + 1][r]);
                }
            }
        }

        return dp[1][n];
    }
};
