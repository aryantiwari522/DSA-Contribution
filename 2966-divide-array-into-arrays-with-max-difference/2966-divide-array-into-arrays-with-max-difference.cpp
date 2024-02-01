class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        // Check if it's possible to divide the array into arrays of size 3
        if (n % 3 != 0) {
            return result; // Return empty array if not possible
        }

        for (int i = 0; i < n; i += 3) {
            // Construct array of size 3
            vector<int> array{nums[i], nums[i + 1], nums[i + 2]};

            // Check if the difference between any two elements in the array is
            // less than or equal to k
            if (array[2] - array[0] <= k) {
                result.push_back(array);
            } else {
                // If not possible, return empty array
                return vector<vector<int>>();
            }
        }

        return result;
    }
};