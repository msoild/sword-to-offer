class Solution {
public:
    //notite size
    string replaceSpaces(string &str) {
        string retStr;
        for(auto&x : str) {
            if(x == ' ') retStr += "%20";
            else retStr += x;
        }
        return retStr;
        
    }
};