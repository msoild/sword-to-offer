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
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        
        if(root == nullptr) return res;
        std::queue<TreeNode*>q;
        q.push(root);
        //nullptr seperate flag
        q.push(nullptr);
        std::vector<int>layer;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(!t) {
                //no child node
                if(layer.empty()) break;
                
                res.push_back(layer);
                layer.clear();
                q.push(nullptr);
                continue;
            }
            layer.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            
        }
        return res;    
    }
    
};