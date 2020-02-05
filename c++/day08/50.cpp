/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //暂时用先序遍历做
 
class Solution {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
      
        dfs_s(root, res);
       
        return res;
        
    }
     
    void dfs_s(TreeNode* root, string& res) {
        if(!root) {
            res += "null ";
            return;
        }
        res += to_string(root->val) + ' ';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
        
    }
       

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int indexOfStr = 0;
       
        
        return dfs_d(data, indexOfStr);
       
    }
    TreeNode* dfs_d(string& data, int& u) {
        if(u == data.size()) return nullptr;
        int k = u;
        while(k < data.size() && data[k] != ' ' ) k ++;
        if(data[u] == 'n') {
            u = k + 1;
            return nullptr;
        }
        
        string valStr = data.substr(u, k);

        int val = atoi(valStr.c_str());
      
        u = k + 1; //跳过空格
        TreeNode* root = new TreeNode(val);
        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);
        return root;
        
        
    }
    
};