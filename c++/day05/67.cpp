class Solution {
/*
有序排列的问题可以用二分查找法
如果mid 是答案的话 mid = l + r + 1>>2
*/
    
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() -1 ;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] < k) l = mid + 1;
            else r = mid;
        }
        if(k != nums[r]) return 0;
      
        int left = l;
        r = nums.size() -1;
        while(l < r) {
            int mid = l +r + 1 >>1;
            if(nums[mid] > k) r = mid -1;
            else  l = mid;
            
            
        }
        int res = r -left + 1;
        return res;
        
    }
};