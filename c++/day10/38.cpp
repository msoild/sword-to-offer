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
 采用递方式
 退出如果节点是空
 */
class Solution {
public:
    void mirror(TreeNode* root) {
        if(root == nullptr) return;
        
        auto p = root->left;
        root->left = root->right;
        root->right = p;
        mirror(root->left);
        mirror(root->right);
        
        
    }
};