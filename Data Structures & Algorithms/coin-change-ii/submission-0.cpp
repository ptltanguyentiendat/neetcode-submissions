class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 5, 0);
        int n = coins.size();
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= amount; j++){
                if(dp[j - coins[i]]) dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
