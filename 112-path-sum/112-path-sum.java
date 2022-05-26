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
    int sum = 0; boolean flag = false;
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null){
            return false;
        }
        sum = sum+root.val;
        if(root.right == null && root.left == null){
            if(sum == targetSum){
                flag = true;
                return true;
            }
        }
        hasPathSum(root.right, targetSum);
        hasPathSum(root.left, targetSum);
        sum = sum - root.val;
        return flag;
    }
}