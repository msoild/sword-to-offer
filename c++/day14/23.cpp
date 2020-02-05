class Solution {
public:
    bool hasPath(vector<vector<char>>& matrix, string str) {
        for (int i = 0; i < matrix.size(); i ++ )
            for (int j = 0; j < matrix[i].size(); j ++ )
                if (dfs(matrix, str, 0, i, j))
                    return true;
        return false;
    }
    
    /*
    * 递归返回的条件是1. 当前枚举matrix 字符 == str[curIndex] 2. indexOfStr 遍历到\0 之前 
    */
    bool dfs(vector<vector<char>> &matrix, string &str, int indexOfStr, int x, int y) {
        if (matrix[x][y] != str[indexOfStr]) return false;
        if (indexOfStr == str.size() - 1) return true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char t = matrix[x][y];
        matrix[x][y] = '*';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size()) {
                if (dfs(matrix, str, indexOfStr + 1, a, b)) return true;
            }
        }
        matrix[x][y] = t;
        return false;
    }
};

