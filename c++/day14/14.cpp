/**
 * 二分思想
 * 抽屉原理 本来一个萝卜一个坑， 多塞进去的就是答案
 */
 
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int r ,l;
        l = 0;
        r = nums.size() -1;
        while(l < r) {
            int mid = (r + l) >>1;
            int numOfLowerThanMid = 0;
            for(auto& x: nums ) numOfLowerThanMid +=  x>=l && x <=mid;
            if(numOfLowerThanMid > (mid-l+1)) r = mid;
            else l =  mid+1;

        }

        return r;
        
    }
};