class Solution {
public:
/*
 * 典型的数学题， 没啥思路
   抽象数学化 N = n1 + n2 + n3 + ... n      max = n1 * n2 * n3 * ...* n
   根据题大概测试3拆分越多越好，剩余 数只能是2 ,不蹦出现1 
*/
    int maxProductAfterCutting(int n)
    {
        if( n <=3 ) return (n-1) *1;
        int res = 1;
        if( n % 3 == 1 ) n -= 4, res *= 4;
        if( n % 3 == 2 ) n -= 2, res *= 2;
        while( n != 0) res *= 3, n -= 3;
        return res;
        
        
    }
};