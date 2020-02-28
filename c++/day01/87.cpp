class Solution {
public:
    int strToInt(string str) {
     
        int res = 0;
         if(str.size() == 0) return res;
        int i = 0, j = str.size() -1;
        while(i <= j && str[i] == ' ') i ++;
        if((str[i] <= '0' || str[i] >= '9') && (str[i] != '-' && str[i] != '+') ) return res;
        while(i <= j && (str[j] <= '0' || str[j] >= '9')) j --;
        str = str.substr(i, j - i + 1 );
        
      
        bool bMinus = false;
        if(str[0] == '-' )
        {
          bMinus = true;;
           str = str.substr(1);
          
        }
        else if(str[0] == '+' )
        {
          
           str = str.substr(1);
          
        }
     
        long long sum = 0;
        for(auto c : str) sum *= 10, sum += (c - '0');
        if(bMinus) sum *= (-1);
        if(sum > INT_MAX) res = INT_MAX;
        else if(sum < INT_MIN) res = INT_MIN;
        else res = sum;
       
        return res;
        
    }
};