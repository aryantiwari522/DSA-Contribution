class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n = arr.size();
    vector<int> dp(n + 1, 0); // dp[i] represents the maximum sum we can get by partitioning the subarray arr[0...i-1]
    
    for (int i = 1; i <= n; ++i) {
        int max_val = 0;
        for (int j = 1; j <= min(k, i); ++j) {
            max_val = max(max_val, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + max_val * j);
        }
    }
    
    return dp[n];
    }
};