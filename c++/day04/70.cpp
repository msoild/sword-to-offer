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
    TreeNode* res;
public:
    TreeNode* kthNode(TreeNode* root, int k) {
        dfs(root, k);
        return res;
        
    }
    void dfs(TreeNode* root, int& k) {
        if(!root)  return ;
        TreeNode* p ;
        dfs(root->left, k);
        k --;
        if(!k) {
            res = root;
            return;
        }
        dfs(root->right, k);
       
    }
};