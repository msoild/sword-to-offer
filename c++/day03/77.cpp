class Solution {
public:
    string reverseWords(string s) {
        //end 都指向最后一个元素的后一个
        reverse(s.begin(), s.end());
        int size = s.size();
        
        for(int i = 0; i < size; ) {
            int j = i;
            while(j < size && s[j] != ' ') j ++;
            //reverse 指向最后一个元素的后一个
            reverse(s.begin() + i, s.begin() + j -1);
            i = j + 1; //j 指向当前单词后面的空格
        }
       
        return s;
        
    }
};