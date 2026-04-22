class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];

        int m = sum/2;
        if(sum % 2) return false;
        vector<int> dp(1000000, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = m; j >= nums[i]; j--){
                if(dp[j - nums[i]]) dp[j] = 1;
            }
        }
        return dp[m];
    }
};
