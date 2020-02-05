class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int j = s.size() -1 ;
        while( i <= j && s[i] == ' ') i ++;
        while( i <= j && s[i] == ' ') j --;
        
        if(i > j) return false;
        
        s = s.substr(i, j - i +1) ;
        if(s[0] == '-' || s[0] == '+') s =s.substr(1);
        if(s.size() == 0 || (s.size() == 1 && s[0] =='.')) return false ;//delete - = .case;
        
        int dotNum = 0;
        int eNum = 0;

        for(int i = 0; i < s.size(); i ++ ) {
            if(s[i] >= '0' && s[i] <= '9'); //do noting ,this index;
            else if(s[i] == '.') {
                dotNum ++;
                if(dotNum > 1 || eNum != 0) return false; //delete 123.456.789  12e+4.49 case
                
            }
            else if(s[i]  == 'e' || s[i] == 'E') {
                eNum ++;
                if( eNum > 1 || i == 0 || i == (s.size() - 1) || (i == 1 && s[i -1] == '.')) return false; //delete 22e2233e 12e e12 .e case
                
                if( (i+1 < s.size()) && s[i + 1] == '-' || s[i + 1] == '+') {
                    if((i + 1) == s.size() - 1) return false;
                    i++;
                }
            }
            else return false;
            
               
        }
        return true;
        
    }
};