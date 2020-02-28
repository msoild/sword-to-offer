//一个哈希表的用法
class Solution {
public:
    char firstNotRepeatingChar(string s) {
        char res = '#';
        unordered_map<char, int> count;
        for(auto& c : s) count[c]++;
        for(auto& c : s) {
            if(count[c] == 1) {
                res = c;
                break;
            }
        }
         return res;
    }
};