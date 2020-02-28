class Solution {
/*
双指针
注意for 循环的临时变量
*/
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>>res;
        for(int i = 1, j = 1, s = 1; i < (sum <<1); i ++) {
            while(s < sum) s += (++j);
            if(s == sum && (j-i) >=1) {
                vector<int>layer;
                for(int k = i ;k <=j; k++) {
                    layer.push_back(k);
                }
                res.push_back(layer);
            }
            
            s = s -i;
            
        }
        return res;
        
    }
};