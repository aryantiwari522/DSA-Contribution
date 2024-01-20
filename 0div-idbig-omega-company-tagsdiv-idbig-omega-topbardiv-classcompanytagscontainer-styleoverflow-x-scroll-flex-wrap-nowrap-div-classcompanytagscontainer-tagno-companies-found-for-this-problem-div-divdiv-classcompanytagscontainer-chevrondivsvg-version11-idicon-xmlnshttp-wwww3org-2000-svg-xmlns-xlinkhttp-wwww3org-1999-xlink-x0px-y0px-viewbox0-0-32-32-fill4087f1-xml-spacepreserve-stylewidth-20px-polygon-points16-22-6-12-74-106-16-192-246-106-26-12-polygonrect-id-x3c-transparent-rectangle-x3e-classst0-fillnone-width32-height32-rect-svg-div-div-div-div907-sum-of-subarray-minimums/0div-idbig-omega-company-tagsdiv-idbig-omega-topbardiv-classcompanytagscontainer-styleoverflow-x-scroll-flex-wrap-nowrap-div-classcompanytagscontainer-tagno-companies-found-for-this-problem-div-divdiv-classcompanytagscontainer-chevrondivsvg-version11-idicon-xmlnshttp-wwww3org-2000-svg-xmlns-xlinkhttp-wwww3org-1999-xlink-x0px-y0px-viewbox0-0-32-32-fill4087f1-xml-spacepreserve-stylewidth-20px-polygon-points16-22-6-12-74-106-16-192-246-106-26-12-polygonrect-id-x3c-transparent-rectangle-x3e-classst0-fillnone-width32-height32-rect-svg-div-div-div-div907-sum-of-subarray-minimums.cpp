class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long result = 0;

        std::stack<int> s;  // stack to store indices
        std::vector<long long> left(n), right(n);

        // Calculate left boundaries
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        // Clear the stack for the next iteration
        while (!s.empty()) {
            s.pop();
        }

        // Calculate right boundaries
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        // Calculate the sum of subarray minimums
        for (int i = 0; i < n; ++i) {
            result = (result + arr[i] * left[i] * right[i]) % MOD;
        }

        return result;
    }
};