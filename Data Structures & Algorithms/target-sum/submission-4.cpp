class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       /// dp[i][total]: số cách tạo total khi xét i - 1 số đầu tiên
       int n = nums.size();
       vector<unordered_map<int, int>> dp(n + 5);

       dp[0][0] = 1;

       for(int i = 0; i < n; i++){
          for(auto x: dp[i]){
            dp[i + 1][x.first + nums[i]] += x.second;
            dp[i + 1][x.first - nums[i]] += x.second;
          }
       }
       return dp[n][target];
    }
};
