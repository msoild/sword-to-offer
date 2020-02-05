/*
解决方法：
    动态规范方法 + 时间记忆法

动态规划状态转移法
1. 建立状态转移方程
2. 缓存并存储以往结果
3. 按照顺序往后（大）计算


分析：(1)              (2)
[P]   a b * c        a b * c       a b * c
[S]   a c            a b b c       a b c


状态表示 f[i][j] 便是 p(j ...) , s(i, ...) p 从j位置开始 去匹配s 从i 开始

状态转移 如果p[j] 是正常字符  f[i][j] = p[j] == s[i] && f[i + 1][j + 1]
         如果p[j] 是 .        f[i][j] = f[i + 1][j + 1]
                                
                               * case(1)                      case(2)
         如果p[j +1] 是*      f[i][j] = p[j + 2] == s[i]  || f[i][j] = f[j][i +1] 
*/              
class Solution {
    
private:
    std::vector<std::vector<int>> f;
    int m, n ;
public:
    bool isMatch(string& s, string& p) {
        // if (s.size() == 0 || p.size() == 0) return true;
        n = s.size() ;
        m = p.size() ;
        f = std::vector<std::vector<int>>(n + 1, std::vector<int>(m  + 1, -1) );
   
        return dp(0, 0, s, p);\
        
      
        
    }
    
    bool dp(int x, int y, string& s, string& p) {
        if (f[x][y] != -1) return f[x][y];
        if (y == m)
            return f[x][y] = x == n;
        bool first_match = x < n && (s[x] == p[y] || p[y] == '.');
        bool ans;
        if (y + 1 < m && p[y + 1] == '*')
        {
            ans = dp(x, y + 2, s, p) || first_match && dp(x + 1, y, s, p);
        }
        else
            ans = first_match && dp(x + 1, y + 1, s, p);
        return f[x][y] = ans;


        
        
        
        
        
    }
};

// TODo
//边界条件