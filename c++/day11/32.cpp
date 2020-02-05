class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i=0,j=array.size()-1;
        while(i<j){
            //找到前面第一个偶数
            //找到后面第一个奇数
            while(i<j && array[i]%2==1) i++;
            while(i<j && array[j]%2==0) j--;
            //奇数和偶数交换
            if(i<j) swap(array[i],array[j]);
        }
    }
};