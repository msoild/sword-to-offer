class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        mStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if(cache.empty()) {
            while(!mStack.empty()) {
                int data = mStack.top();
                cache.push(data);
                mStack.pop();   
            }
            
        }
        
        if(cache.empty()) return 0;
        res = cache.top();
        cache.pop();
        return res;
        
    }
    
    /** Get the front element. */
    int peek() {
         int res;
        if(cache.empty()) {
            while(!mStack.empty()) {
                int data = mStack.top();
                cache.push(data);
                mStack.pop();   
            }
            
        }
        
        // if(cache.empty()) return 0;
        res = cache.top();
      
        return res;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mStack.empty()&& cache.empty();
        
    }
private:

    

    std::stack<int> mStack, cache;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

//need to been done 两个queue, 实现一个stack