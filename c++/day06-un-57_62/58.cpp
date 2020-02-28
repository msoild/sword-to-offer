class Solution {
public:
    static bool  compareStrConn(int& a, int& b) {
        if((to_string(a) + to_string(b)) < (to_string(b) + to_string(a))) return true;
        else return false;
    }
    
    string printMinNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), compareStrConn);
        for(auto&& x : nums) {
            res += to_string(x);
        }
        return res;
    }
    
    
