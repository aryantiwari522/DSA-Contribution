class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);

        // Left-to-right pass
        int cumValue = 0, cumValueSum = 0;
        for (int i = 0; i < n; ++i) {
            result[i] += cumValueSum;
            cumValue += (boxes[i] == '1') ? 1 : 0;
            cumValueSum += cumValue;
        }

        // Right-to-left pass
        cumValue = 0, cumValueSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += cumValueSum;
            cumValue += (boxes[i] == '1') ? 1 : 0;
            cumValueSum += cumValue;
        }

        return result;
    }
};