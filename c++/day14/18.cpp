

//牛客网 answer
//https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() != vin.size() || pre.size() == 0 || vin.size() ==0 ) {
            return nullptr;
        }
        int maxIndex =  pre.size() -1;
        int* pPreStart = &pre[0];
        int* pPreEnd = &pre[maxIndex];
        int* pInStart = &vin[0];
        int* pInEnd = &vin[maxIndex];
        return constructCore(pPreStart, pPreEnd, pInStart, pInEnd);
    }
    
 
    
    TreeNode* constructCore(int* pPreStart, int* pPreEnd, int* pInStart, int* pInEnd) {
        if(pPreStart == nullptr || pPreEnd == nullptr || pInStart == nullptr || pInEnd == nullptr) {
            return nullptr;
        }
        int rootValue = pPreStart[0];
        TreeNode* root = new TreeNode(rootValue);
        root->left = nullptr;
        root->right = nullptr;
        
        //only one node remain
        if(pPreStart == pPreEnd) {
            if(pInStart == pInEnd && *pPreStart == *pInStart) {
                return root;
            }
        }
        
        int* pRootOfIn = pInStart;
        while(  pRootOfIn  <= pInEnd  && *pRootOfIn != rootValue  ) {
            ++ pRootOfIn ;
        }
        int leftLen = pRootOfIn - pInStart;
        int* pPreLeftEnd =  pPreStart + leftLen;
        if(leftLen > 0) {
           root->left = constructCore(pPreStart + 1, pPreLeftEnd, pInStart, pRootOfIn -1 );
        }
        if(leftLen < pPreEnd - pPreStart ) {
           root->right = constructCore(pPreLeftEnd +1, pPreEnd, pRootOfIn +1, pInEnd);
        }
        return root;
       
    }
};