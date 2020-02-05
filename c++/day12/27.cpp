#define MIN_VALUE 1e-8
#define IS_DOUBLE_ZERO(d)  (abs(d) < MIN_VALUE)
class Solution {

/*
    (-2)^3 = -8
    ( 2)^3 = 8;
    ( 2)^(-2) = 0.25 
*/
public:

    double Power(double b, int e) {
        if(IS_DOUBLE_ZERO(b) && e == 0) return 0;
        double res = 1;
        for(int i = 0; i< abs(e); i++) {
            res *= b;
        }
        if(e < 0) res = 1 / res;
        return res;
    }
};