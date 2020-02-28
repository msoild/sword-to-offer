class Solution {
/*
双指针问题
*/
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        std::vector<int>res;
        
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            if((nums[i] + nums[j]) == target) {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                break;
            }
           
            else if((nums[i] + nums[j]) < target) i ++;
            else  j --;
        }
        return res;
    }
    
  
};