/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归一般是深度优先算法
 //层级遍历需要广度优先算法
   // 1. 队列数据结构辅助存储
class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
        std::vector<int>vec;
        if(!root) return vec;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            //打印当前节点，
            auto t = q.front();
            q.pop();
            vec.push_back(t->val);
            //存储下一层的指针到节点中
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return vec;
        
    }
};