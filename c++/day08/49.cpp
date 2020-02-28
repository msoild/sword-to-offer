/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 采用递归方法
 采用pair 保存当前节点最左边的店 和当前节点最右边的店
 */
class Solution {
public:
    TreeNode* convert(TreeNode* root) {
        if(root == nullptr) return root;
        auto sides =  dfs(root);
        return sides.first;
    }
    std::pair<TreeNode*, TreeNode*> dfs(TreeNode* root) {
        if(!root->left && !root->right) return {root, root};
        if(root->left && root->right) {
            auto lsides = dfs(root->left);
            auto rsides = dfs(root->right);
            lsides.second->right = root, root->left = lsides.second;
            rsides.first->left = root, root->right = rsides.first;
            return {lsides.first, rsides.second};
        }
        
        if(root->left && !root->right) {
            auto lsides = dfs(root->left);
            lsides.second->right = root, root->left = lsides.second;
            return {lsides.first, root};
        }
        
        if (!root->left && root->right) {
            auto rsides = dfs(root->right);
            rsides.first->left = root, root->right = rsides.first;
            return {root, rsides.second};
          
        }
    }
    
};