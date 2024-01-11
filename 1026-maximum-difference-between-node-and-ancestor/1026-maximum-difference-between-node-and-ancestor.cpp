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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return helper(root, root->val, root->val);
    }

private:
    int helper(TreeNode* node, int mn, int mx) {
        if (!node) return mx - mn;
        
        // Update the minimum and maximum values encountered so far on the path
        mn = std::min(mn, node->val);
        mx = std::max(mx, node->val);
        
        // Recursively find the maximum difference in the left and right subtrees
        int leftDiff = helper(node->left, mn, mx);
        int rightDiff = helper(node->right, mn, mx);
        
        // Return the maximum difference between the left and right subtrees
        return std::max(leftDiff, rightDiff);
    }
};
