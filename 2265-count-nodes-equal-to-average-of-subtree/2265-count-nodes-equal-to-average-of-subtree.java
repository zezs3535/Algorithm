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
    int ans = 0;
    public int averageOfSubtree(TreeNode root) {
        search(root);
        return ans;
    }
    
    public int[] search(TreeNode node){
        if(node == null) return new int[]{0,0};
        
        int[] left = search(node.left);
        int[] right = search(node.right);
        
        int curSum = left[0] + right[0] + node.val;
        int curCnt = left[1] + right[1] + 1;
        
        if(curSum / curCnt == node.val)ans++;
        
        return new int[]{curSum, curCnt};
    }
}