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
public:
    int treeDepth(TreeNode* root) {
        if(!root) return 0;
        int k = 0;
        return dfs(root, k);
        
    }
    
    int dfs(TreeNode* root, int k) {
        if(!root) return k;
        k +=1;
        int lDeep = dfs(root->left, k);
        int rDeep = dfs(root->right, k);
        return lDeep > rDeep ? lDeep : rDeep;
    }
};