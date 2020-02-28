class Solution{
private:
    unordered_map<char, int> cnt;
    queue<char>q;
public:
    //Insert one char from stringstream
    void insert(char ch){
        if(++cnt[ch] > 1) {
            while(q.size() && (cnt[q.front()] > 1)) q.pop();
        }
        else q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        char res = '#';
        if(!q.empty()) res = q.front();
        return res;
        
    }
};