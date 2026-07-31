/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
      if(root == null) return 0; 

        // 1. Calculate path passing through the current root
        int leftHeight = heightOfTree(root.left); 
        int rightHeight = heightOfTree(root.right); 
        int currentDiameter = leftHeight + rightHeight;

        // 2. Recursively find the max diameter in left and right subtrees
        int leftSubtreeDiameter = diameterOfBinaryTree(root.left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root.right);

        // 3. Return the maximum of the three paths
        return Math.max(currentDiameter, Math.max(leftSubtreeDiameter, rightSubtreeDiameter)); 
    }
     public int heightOfTree(TreeNode root) {
        if(root == null) return 0;
        int leftHeight = heightOfTree(root.left);
        int rightHeight = heightOfTree(root.right);
        return (Math.max(leftHeight,rightHeight)+1);

    }
}