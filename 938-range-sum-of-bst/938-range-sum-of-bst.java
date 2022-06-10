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
    static int low;
    static int high;
    static int ans;
    public int rangeSumBST(TreeNode root, int low, int high) {
        this.low = low;
        this.high = high;
        ans = 0;
        go(root);
        return ans;
    }
    
    public void go(TreeNode root){
        if(root == null)return;
        if(root.val >= low && root.val <= high) {ans += root.val;
                                                 //System.out.println(root.val);
                                                }
        go(root.left);
        go(root.right);
    }
}