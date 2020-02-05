/**
 *[
  [1,2,8,9]，
  [2,4,9,12]，
  [4,7,10,13]，
  [6,8,11,15]
]
hen
 */
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty() || array[0].empty()) return false;
        int rowIndex = 0;
        int rowNum = array.size();
        int colIndex = array[0].size()-1;
        while(colIndex>=0 && rowIndex < rowNum) {
            if (array[rowIndex][colIndex] == target) return true;
            if (array[rowIndex][colIndex] > target) colIndex--;
            else rowIndex ++;
        }
        
        return false;
           
    }
};