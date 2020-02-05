class Solution {
/*
栈的操作
1. pop
2. push

针对该题
栈中先放入一个元素
1. 如果栈顶元素 = 输出序列当前值 弹出（现在不弹出后面没机会了）
2. 如果栈顶元素 != 输出序列当前值继续 push
*/
public:
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()) return false;
        if(pushV.empty() && popV.empty()) return true;
        
        int i = 0;
        std::stack<int>stk;
        
       for(auto& x :pushV) {
           stk.push(x);
           
           while(!stk.empty() && stk.top() == popV[i]) {
               stk.pop();
               i ++;
           }
       }
       
       return stk.empty();
        
    }
};