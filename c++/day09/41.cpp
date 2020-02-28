class MinStack {
//双栈空间换时间的题
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        mStack.push(x);
        if(mMinStack.empty() || x<= mMinStack.top()) mMinStack.push(x);
    }
    
    void pop() {
        if(mStack.top() == mMinStack.top()) mMinStack.pop();
        mStack.pop();
    }
    
    int top() {
        return mStack.top();
    }
    
    int getMin() {
        return mMinStack.top();
    }
    std::stack<int>mStack;
    std::stack<int> mMinStack; //copy the min value
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */