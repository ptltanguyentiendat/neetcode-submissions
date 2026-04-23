class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;
        s1 = " " + s1; s2 = " " + s2, s3 = " " + s3;
        /// dp[i][j]: xét vị trí i trong s1, j trong s2;
        vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            if(s1[i] == s3[i] && dp[i - 1][0]) dp[i][0] = 1;
        }
        for(int j = 1; j <= m; j++){
            if(s2[j] == s3[j] && dp[0][j - 1]) dp[0][j] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i] == s3[i + j] && dp[i - 1][j]) dp[i][j] = 1;
                if(s2[j] == s3[i + j] && dp[i][j - 1]) dp[i][j] = 1;
            }
        }
        return dp[n][m];
    }

};
