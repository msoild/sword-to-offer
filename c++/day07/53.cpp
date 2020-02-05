class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        //从小到大排列
        priority_queue<int> heap;
        for(auto& x : input) {
            heap.push(x);
            while(heap.size() > k) {
                heap.pop();
            }
        }
        while(heap.size()) {
            res.push_back(heap.top());
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
        
    }
};