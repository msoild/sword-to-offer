class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size() -1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if((nums[mid] - mid)  > 0) r = mid -1;
            else l = mid;
        }
        int res = -1;
        if(nums[l] == l) {
            res = l;
        }
        return res;
        
    }
};