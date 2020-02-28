class Solution {
public:
    string leftRotateString(string str, int n) {
       reverse(str.begin(), str.end());
       reverse(str.begin(), str.end() - n);
       reverse(str.end() -n, str.end());
        return str;
    }
};