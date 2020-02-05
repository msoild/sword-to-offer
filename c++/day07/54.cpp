/*利用大小堆求解一个不断更新的数组的中位数。
   大根堆存储前0到n/2 +1个数字
                    
，小根堆存储剩下的数字，可以看出大根堆和小根堆的顶部就是我们需要的值。
此时我们必须维护好两个堆中元素的个数关系，元素的大小关系，
即大根堆的所有元素理应比小根堆的所有元素要小，如果违反了此规则，就需要进行元素的对换。
*/

class Solution {
public:
    void insert(int num){
        maxHeap.push(num);
        if(minHeap.size() != 0 && maxHeap.top() > minHeap.top()) {
            auto minTop = minHeap.top(), maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.pop();
            
            minHeap.push(maxTop), maxHeap.push(minTop);
        }
       if(maxHeap.size()  > (minHeap.size() + 1)) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
    }

    double getMedian(){
        double res;
        if((maxHeap.size() + minHeap.size()) & 1) res = maxHeap.top(); 
        else res = (maxHeap.top() + minHeap.top()) /2.0;
        return res;
    }
private:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};