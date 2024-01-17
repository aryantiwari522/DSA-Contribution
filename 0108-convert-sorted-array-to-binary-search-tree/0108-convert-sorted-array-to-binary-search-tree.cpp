/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBSTHelper(std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr; // Empty subtree
        }

        // Find the middle element
        int mid = left + (right - left) / 2;

        // Create the root node
        TreeNode* root = new TreeNode(nums[mid]);
        if(left==right)
        {
            return root;
        }
        // Recursively build the left and right subtrees
        root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, right);

        return root;
    }
};