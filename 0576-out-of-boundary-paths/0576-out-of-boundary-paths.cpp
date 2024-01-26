class Solution {
public:
    const int MOD = 1e9 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        std::vector<std::vector<std::vector<int>>> dp(
            m,
            std::vector<std::vector<int>>(n, std::vector<int>(maxMove + 1, 0)));

        // Initialize base case: starting cell with 0 moves has 1 way
        dp[startRow][startColumn][0] = 1;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int result = 0;

        // Iterate over the number of moves
        for (int move = 1; move <= maxMove; ++move) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + directions[d][0];
                        int nj = j + directions[d][1];

                        // Check if the new position is within the grid
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            dp[i][j][move] =
                                (dp[i][j][move] + dp[ni][nj][move - 1]) % MOD;
                        } else {
                            // If the new position is outside the grid,
                            // increment the result
                            result = (result + dp[i][j][move - 1]) % MOD;
                        }
                    }
                }
            }
        }

        return result;
    }
};