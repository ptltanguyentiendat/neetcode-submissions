class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 5, 0);
        dp[0] = 1;
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= 2; i++){
                dp[j] += dp[j - i];
            }
        }
        return dp[n];
    }
};
