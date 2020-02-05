class Solution {
    //绝妙的答题思路啊
public:
    int NumberOf1(int n) {
        unsigned un = n;
        int res = 0;
        while(un != 0) res += un & 1, un >>= 1;
        return res;
    }
};