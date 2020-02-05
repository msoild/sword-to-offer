/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //
 
 /*
 1. 二叉树的题一般采用递归的思路
 */
class Solution {
public:
    bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if( !pRoot1 || !pRoot2) return false;
        
        if(isSame(pRoot1, pRoot2)) return true;
        
        return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
    }
    
    bool isSame(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot2) return true;
        if(!pRoot1 || (pRoot1->val != pRoot2->val)) return false;
        return isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);
    }
};

//TODO 字符串匹配的问题
