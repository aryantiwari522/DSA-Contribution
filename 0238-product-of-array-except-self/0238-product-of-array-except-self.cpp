class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    std::vector<int> leftProduct(n, 1); // Store product of elements to the left
    std::vector<int> rightProduct(n, 1); // Store product of elements to the right
    std::vector<int> result(n);

    // Calculate product of elements to the left
    for (int i = 1; i < n; ++i) {
        leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
    }

    // Calculate product of elements to the right
    for (int i = n - 2; i >= 0; --i) {
        rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
    }

    // Multiply the left and right products to get the result
    for (int i = 0; i < n; ++i) {
        result[i] = leftProduct[i] * rightProduct[i];
    }

    return result;
    }
};