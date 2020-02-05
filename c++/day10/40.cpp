class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        std::vector<int>res;
        int n = matrix.size() ;
        if(n == 0) return res;
        int m = matrix[0].size();
        std::vector<std::vector<bool>>st(n, std::vector<bool>(m, false));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0,  1, 0 ,-1};
        int d = 1;
        int x = 0 , y = 0;
        
        for(int i = 0; i < m *n; i++) {
            
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            
            // //采用临时变量试探了下
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >=n || b < 0 || b >= m || st[a][b] ) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x =a , y =b;
        }
        
        
    return res;
        
    }
};