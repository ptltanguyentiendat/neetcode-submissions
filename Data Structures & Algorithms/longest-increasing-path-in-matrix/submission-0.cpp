class Solution {
private:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    /// dp[i][j]]: đường đi dài nhất xuất phải từ [i, j]
    int n, m;
    int DFS(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(dp[row][col] != 0) return dp[row][col];

        int max_len = 1;
        for(int k = 0; k < 4; k++){
            int next_row = row + dx[k],
                next_col = col + dy[k];

            if(next_row >= 0 && next_row < n && 
            next_col >= 0 && next_col < m && 
            matrix[next_row][next_col] > matrix[row][col]){
                max_len = max(max_len, DFS(next_row, next_col, matrix, dp) + 1);
            }
        }
        return dp[row][col] = max_len;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       n = matrix.size(); m = matrix[0].size();
       vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));

       int longest_path = 0;

       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            longest_path = max(longest_path, DFS(i, j, matrix, dp));
        }
       }
       return longest_path;
    }
};
