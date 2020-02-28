//双指针一般两个指针都能动

class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        int res = 0;
        unordered_map<char, int> hash;
        for(int i = 0, j = 0; j < s.size(); j ++) {
            hash[s[j]] ++;
            while(hash[s[j]] > 1)
            {
                hash[s[i]] --;
                i ++;
            }
            res = max(res, j -i + 1);
        }
        return res;
    }
};