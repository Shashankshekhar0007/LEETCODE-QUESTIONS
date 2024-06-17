class Solution {
public:
    // int solve(vector<vector<char>>& matrix, vector<vector<int>>& dp, int& maxi,
    //           int i, int j) {
    //     if (i >= matrix.size() || j >= matrix[0].size()) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int right = solve(matrix, dp, maxi, i, j + 1);
    //     int down = solve(matrix, dp, maxi, i + 1, j);
    //     int diagonal = solve(matrix, dp, maxi, i + 1, j + 1);
    //     if (matrix[i][j] == '1') {
    //         dp[i][j] = 1 + min(right, min(down, diagonal));
    //         maxi = max(maxi, dp[i][j]);
    //         return dp[i][j];
    //     } else {
    //         return 0;
    //     }
    // }
        // solve(matrix,dp,maxi,0,0);
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = n-1; i>=0; i--) {
            for (int j = m-1; j>=0; j--) {
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                int diagonal = dp[i +1][j + 1];
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(down, diagonal));
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j]=0;
                }
            }
        }
        return maxi * maxi;
    }
};