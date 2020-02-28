class Solution {
/*
混淆点：
1. 移位操作不改变原有的值
思路：
1. 两个相同的值异或操作是0
步骤
异或得到 x^y
取 x与y中第k位为1的数 也就是在第k 位的值是不同的。
将数分为两个集合，第k位为1的集合和第k位不是1的集合
其中x y分别在这两个集合，且相同的元素是在同一个集合里面
于是将其转化成了求重复数字中的单个数值的问题
*/
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        int xorSum = 0;
        for(auto& x : nums) xorSum ^= x;
        int k = 0;
        while( !(xorSum >> k &1)) k ++;
        
        int first = 0;
        for(auto& x : nums) {
            if(x >> k & 1) first ^= x; 
            cout << x <<std::endl;
        }
        return vector{first, xorSum ^ first};
    }
};