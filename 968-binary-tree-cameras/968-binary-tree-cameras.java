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
    private int cameras = 0;
    public int minCameraCover(TreeNode root) {
        return minCameraCover_(root) == -1 ? cameras + 1 : cameras;
    }
    //-1: NOT MONITORED
    //0: MONITORED
    //1: HAS CAMERA
    private int minCameraCover_(TreeNode root) {
        if(root==null){
           return 0;
        }
        int lc = minCameraCover_(root.left);
        int rc = minCameraCover_(root.right);
        if(lc == -1 || rc ==-1){
            cameras++;
            return 1;
        }
        if(lc == 1 || rc ==1){
            return 0;
        }
        return -1;
    }
}