class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        
        if(rows == 0 || cols == 0) return 0;
        int res = 0;
        std::vector<std::vector<bool>> vt(rows, std::vector<bool>(cols, false));
        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = { 0, 1, 0, -1};
        while(q.size() != 0) {
           auto t = q.front();
           q.pop();
           
           if(getDigitSum(t) > threshold || vt[t.first][t.second]) continue;
           vt[t.first][t.second] = true;
           res ++;
           for(int i = 0; i < 4; i ++) {
               int x = t.first + dx[i];
               int y = t.second + dy[i];
               if(x >= 0 && x < rows && y >= 0 && y < cols  )
               q.push({x, y});
           }
            
        }
        
        return res;
    }

private:
    
    int getSingleDigitSum(int x) {
        int s = 0;
        while(x != 0) s += x %10, x = x / 10;
        return s;
    }
    
    int getDigitSum(std::pair<int, int>& p) {
        return getSingleDigitSum(p.first) + getSingleDigitSum(p.second);
    }
};