class Solution {
public:
    int maxDiff(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = 0;
        int minValue = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            res = max(nums[i] - minValue, res);
            minValue = min(nums[i], minValue);
        }
        
        return res;
    }
};