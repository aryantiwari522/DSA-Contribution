class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
         int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;
        
        for (int i = 0; i < rows; ++i) {
            vector<int> prefixSum(cols);
            for (int j = i; j < rows; ++j) {
                unordered_map<int, int> sumCount;
                int currSum = 0;
                for (int k = 0; k < cols; ++k) {
                    prefixSum[k] += matrix[j][k];
                    currSum += prefixSum[k];
                    if (currSum == target)
                        count++;
                    if (sumCount.find(currSum - target) != sumCount.end())
                        count += sumCount[currSum - target];
                    sumCount[currSum]++;
                }
            }
        }
        
        return count;
    }
};