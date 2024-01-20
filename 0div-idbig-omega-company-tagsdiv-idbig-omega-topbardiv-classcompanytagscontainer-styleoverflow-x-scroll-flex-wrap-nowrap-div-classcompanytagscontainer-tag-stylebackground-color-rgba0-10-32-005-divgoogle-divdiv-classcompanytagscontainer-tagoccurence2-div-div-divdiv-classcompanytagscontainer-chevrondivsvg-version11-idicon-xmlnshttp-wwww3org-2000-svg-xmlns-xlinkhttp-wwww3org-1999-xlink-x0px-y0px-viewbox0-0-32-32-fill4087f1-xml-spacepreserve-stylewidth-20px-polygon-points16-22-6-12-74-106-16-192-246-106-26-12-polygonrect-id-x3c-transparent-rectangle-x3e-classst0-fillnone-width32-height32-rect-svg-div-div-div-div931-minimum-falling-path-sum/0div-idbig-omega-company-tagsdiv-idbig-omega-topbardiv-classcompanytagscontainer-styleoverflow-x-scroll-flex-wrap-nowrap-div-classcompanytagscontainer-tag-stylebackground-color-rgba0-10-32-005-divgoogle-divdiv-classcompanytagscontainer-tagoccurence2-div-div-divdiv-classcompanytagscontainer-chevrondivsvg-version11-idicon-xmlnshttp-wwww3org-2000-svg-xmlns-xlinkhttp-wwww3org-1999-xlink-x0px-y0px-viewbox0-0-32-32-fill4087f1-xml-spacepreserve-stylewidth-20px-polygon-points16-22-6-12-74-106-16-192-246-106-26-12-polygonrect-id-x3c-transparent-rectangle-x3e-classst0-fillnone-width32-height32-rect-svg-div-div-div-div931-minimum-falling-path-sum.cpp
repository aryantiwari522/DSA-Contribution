class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Create a DP matrix to store the minimum falling path sum at each
        // position
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the first row of the DP matrix with the values from the
        // input matrix
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }

        // Iterate through the matrix starting from the second row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the minimum falling path sum for the current
                // position
                dp[i][j] =
                    matrix[i][j] + min({dp[i - 1][max(0, j - 1)], dp[i - 1][j],
                                        dp[i - 1][min(n - 1, j + 1)]});
            }
        }

        // Find the minimum falling path sum in the last row of the DP matrix
        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n - 1][j]);
        }

        return minSum;
    }
};