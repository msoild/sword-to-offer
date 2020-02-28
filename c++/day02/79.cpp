class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int>res;
        deque<int> q ;// 维护nums 中有效值得下标
        for(int i = 0; i < nums.size(); i ++) {
            while(!q.empty() && (i - q.front()) >= k) q.pop_front(); //弹出滑过得元素
            while(!q.empty() &&  (nums[q.back()] <= nums[i])) q.pop_back();// 弹出小于新来值得元素
            q.push_back(i);
            if(i >= (k -1)) res.push_back(nums[q.front()]);
        }
      
        return res;
        
    }
};