/*
混淆点
！  逻辑取反 ~ 位取反
*/
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int once = 0, twice = 0;
        for(auto& x : nums) {
            once = once ^ x & ~twice;
            twice= twice ^ x & ~once;
        }
        return once;
    }
};