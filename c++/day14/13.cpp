/**
 * 基本概念
 * 基本步骤
 */
 
class Solution {
public:

    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();

        for(auto& x : nums) {
            if (x<0 || x>n-1) return -1;
        }
        for(int i = 0; i<n; i++) {
            //if no same value break condition i==nums[i] put the right place
            //if find the same value nums[i] == nums[nums[i]]
            while (nums[i] != nums[nums[i]]  && i !=nums[i]) swap(nums[i], nums[nums[i]]);
            if(nums[i] == nums[nums[i]] && i != nums[i]) return nums[i];
        }
        return -1;
        
    }
};