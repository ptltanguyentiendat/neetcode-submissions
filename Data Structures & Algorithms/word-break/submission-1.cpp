class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 5, false);
        int n = s.size();
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                string res = s.substr(j, i - j);
                if(dp[j] && wordSet.find(res) != wordSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
