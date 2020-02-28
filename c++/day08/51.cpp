class Solution {
public:
    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.resize(nums.size());
        dfs(nums, 0, 0, 0);
        return res;
    }
    
    void dfs(vector<int>&nums, int curHandle, int startPlace, int state) {
        if(curHandle == nums.size()) {
            res.push_back(path);
          
          
            return;
        }
        if(curHandle ==0  ||  nums[curHandle] != nums[curHandle - 1]) startPlace = 0;
        for(int i = startPlace; i < nums.size(); i++) {
            if(!((state >> i) & 1) ) {
                path[i] = nums[curHandle];
                dfs(nums, curHandle + 1, i + 1, (state + ( 1 << i)));
            }
            
            
        }
    }
private:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    
};