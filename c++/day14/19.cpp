/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
/**
 * 判断有没有右边节点
 * 判断是不是父节点的左节点
 * 判断父节点是不是祖父或者祖祖父等的左边节点，自己本身是右节点
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        TreeNode* pNext = nullptr;
        if(p == nullptr)  return p;
        else if(p->right != nullptr) {
            p = p->right;
            while(p->left) {
                p = p->left;
            }
            pNext = p;
        }
        
        else if(p->father && p->father->left == p) pNext= p->father;
        else  if(p->father) {
            TreeNode* pF = p->father;
            TreeNode* pCur = p;
            while(pF && pCur == pF->right) {
                pCur = pF;
                pF = pF->father;
            }
           pNext =  pF;
             
        }
        else {
            pNext = nullptr;
        }
        return pNext;
    }
    
};