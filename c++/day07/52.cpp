class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int val = -1, cnt = 0;
        for(auto&x : nums) {
            if(!cnt) val = x, cnt = 1;
            else {
                if(val != x)  cnt --;
                else cnt ++;
            }
        }
        return val;
    }
};