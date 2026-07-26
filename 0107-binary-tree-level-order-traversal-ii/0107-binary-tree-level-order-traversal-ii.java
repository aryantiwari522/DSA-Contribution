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
    List<List<Integer>> result = new ArrayList<>(); 
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null) return result;
        Queue<TreeNode> q =  new LinkedList<>();
        q.add(root);
        q.add(null);
        List<Integer> currList = new ArrayList<>();
        while(!q.isEmpty()){
            TreeNode currNode = q.remove();
            if(currNode == null){
                result.add(currList);
                currList=new ArrayList<>();
                if(q.isEmpty()) break;
                else{
                    q.add(null);
                }
            }
            else{
               currList.add(currNode.val);
                if(currNode.left != null) q.add(currNode.left);
                if(currNode.right != null) q.add(currNode.right);
            }
        }
        Collections.reverse(result);
        return result;
    }
}