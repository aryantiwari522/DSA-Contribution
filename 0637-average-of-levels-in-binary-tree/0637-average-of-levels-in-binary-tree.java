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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> result = new ArrayList<>();
        if(root == null) return result;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);

        double sum=0.0;
        int count=0;
        while(!q.isEmpty()){
            TreeNode currNode = q.remove();
            if(currNode==null){
                double avgValue=(sum)/count;
                result.add(avgValue);
                sum=0.0;
                count=0;
                if(q.isEmpty()) break;
                else{
                    q.add(null);
                }
            }
            else{
                sum+=currNode.val;
                count+=1;
                if(currNode.left!=null) q.add(currNode.left);
                if(currNode.right!=null) q.add(currNode.right);
            }
        }
        return result;
    }
}