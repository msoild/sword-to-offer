class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        for(int i = 0, mul = 1; i < n; i ++) {
            res[i] = mul;
            mul = A[i] * mul;
        }
       
        for(int i = n -1, mul = 1; i >=0; i --) {
            res[i] = res[i] *mul;
            mul = A[i] * mul;
        }
        return res;
    }
};