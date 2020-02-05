/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 深度搜索
 /*
  * 1. 当前层的边界条件
    2. 当前层需要处理的数据
    3. 当前层需要清理的数据
 */
class Solution {
public:
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        dfs(root,  sum);
        return res;
    }
    
    void dfs(TreeNode* root, int sum) {
        if(!root) return;
        path.push_back(root->val);
        int s = sum;
        s = s- root->val;
        if(root->left == nullptr && root->right == nullptr && s ==0) res.push_back(path);
        dfs(root->left, s);
        dfs(root->right, s);
        path.pop_back();
    }
    
private:
    std::vector<std::vector<int>> res;
    std::vector<int>path;
};