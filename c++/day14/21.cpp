class Solution {
public:
    int Fibonacci(int n) {
        // if(n <=0) return 0;
        // if(n ==1 ) return 1;
        // return Fibonacci(n-1) + Fibonacci(n-2);
        int a = 0, b =1;
        while(n--) {
            int s = a + b;
            a = b;
            b = s;
        }
        return a;
        
    }
};

//TO DO LIST
/**
 * 剑指offer 74

*/