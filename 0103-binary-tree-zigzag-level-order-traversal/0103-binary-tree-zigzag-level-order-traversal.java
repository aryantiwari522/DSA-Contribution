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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null) return result;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        List<Integer> currList =  new ArrayList<>();
        int count=-1;
        while(!q.isEmpty()){
            TreeNode currNode = q.remove();
            if(currNode == null){
                if(count>0){ Collections.reverse(currList);}
                result.add(currList);
                count*=-1;
                currList=new ArrayList<>();
                if(q.isEmpty()) break;
                else{
                    q.add(null);
                }
            }
            else{
                currList.add(currNode.val);
                if(currNode.left!= null) q.add(currNode.left);
                if(currNode.right!=null) q.add(currNode.right);
            }
        }
        return result;
    }
}