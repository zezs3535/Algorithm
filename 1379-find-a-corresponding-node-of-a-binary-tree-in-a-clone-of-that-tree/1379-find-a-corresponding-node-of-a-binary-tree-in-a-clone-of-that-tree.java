/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    TreeNode answer = null;
    TreeNode target = null;
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        this.target = target;
        go(original, cloned);
        return answer;
    }
    
    public void go(TreeNode original, TreeNode cloned){
        if(original != null){
            if(original == target)answer = cloned;
            go(original.left, cloned.left);
            go(original.right, cloned.right);
        }
    }
}