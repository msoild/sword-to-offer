/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //空树 也是对称的 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
       
        return  dfs(root->right, root->left);
    }
    
    bool dfs(TreeNode* pR, TreeNode* pL)
    {
        if(pR ==nullptr && pL == nullptr) return true;
        if(pR == nullptr || pL == nullptr) return false; //有一个为空指针
        
        return (pR->val == pL->val) && dfs(pL->left, pR->right) && dfs(pL->right, pR->left);
    }
};