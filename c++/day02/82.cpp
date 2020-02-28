//圆圈中最后剩下的数字
//递归
class Solution {
public:
    int lastRemaining(int n, int m){
        if(n==1)
            return 0;
        else
            return (lastRemaining(n-1,m)+m)%n;
    }
};

#include <list>
class Solution {
public:
    int lastRemaining(int n, int m){
        list<int> nums;
        for (int i = 0; i < n; ++i) nums.push_back(i);
        auto it = nums.begin();
        int k = m - 1;
        while (nums.size() > 1){
            while (k--){
                it++;
                if (it == nums.end()) it = nums.begin();//别迭代器移到开头实现模拟环形列表
            }
            it = nums.erase(it);//删除第m个元素
            if (it == nums.end()) it = nums.begin();
            k = m - 1;
        }
        return nums.front();
    }
};