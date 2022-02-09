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
    int maxDepth = 0;
    
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        findMaxDepth(root,0);
        //get maxDepth
        
        return getAnswer(root,0);
    }
    void findMaxDepth(TreeNode* node, int depth) {
        if(node==NULL){
            maxDepth = max(maxDepth, depth-1);
            return;
        }
        findMaxDepth(node->left,depth+1);
        findMaxDepth(node->right,depth+1);
    }
    
    int getAnswer(TreeNode* node, int depth){
        int sum = 0;
        if(node==NULL){
            return 0;
        }
        if(depth==maxDepth){
            return node->val;
        }
        
        sum += getAnswer(node->left,depth+1);
        sum += getAnswer(node->right,depth+1);
        return sum;
    }
};