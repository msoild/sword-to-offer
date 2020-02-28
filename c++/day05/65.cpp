/*
归并排序的思路
先分开，直到每个拆分数据是1或者2
先后比较排序

递归步骤
1. 如果 l >=r 只剩一个元素 return
2. 当前层拆分l, mid ;mid+ 1 r 两部分
3. 合并 排序
    1.需要O(n) 的tmp 空间存储当前数据
    2. 两部分派出代表比较 谁小 谁派出后面代表， 并把小的数放tmpvector 里面
    3. 如果有一部分没比较完， 没比较完的部分全部放在tmp vector里面
    4. 把tmp vector 里面的东西重新放在原始数组里
*/
class Solution {
public:
    int merge(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;
        int res = 0;
        int mid = l + r >> 1;
        res = merge(nums, l, mid) + merge(nums, mid + 1, r);
        int i = l, j = mid + 1;
        vector<int> tmp;
        while(i <=mid && j <= r ) {
            if(nums[i] <= nums[j]) tmp.push_back(nums[i++]);
            else {
                tmp.push_back(nums[j++]);
                res += mid - i + 1; 
            }
            
        }
        while(i <= mid) tmp.push_back(nums[i++]);
        while(j <= r) tmp.push_back(nums[j++]);
        
        int k = l;
        for(auto&x : tmp) nums[k++] = x; 
        return res;
        
    }
    int inversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size() -1);
        
    }
};