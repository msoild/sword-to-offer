/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isBal = true;
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return isBal;
        
    }
    
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int lDeep = dfs(root->left);
        int rDeep = dfs(root->right);
        if(abs(lDeep - rDeep) > 1) isBal = false;
        return max(lDeep, rDeep) + 1;
    }
};