class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 5);
        for(int i = 0; i <= amount; i++) dp[i] = 10000000;
        dp[0] = 1;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i >= coins[j]) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if(dp[amount] != 10000000) return dp[amount] - 1;
        return -1;
    }
};
