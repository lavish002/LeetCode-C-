class Solution {
public:
    unordered_map<int,bool> mem;
    
    bool isValid(string s, vector<string> wordDict){
        for(int i=0; i<wordDict.size(); i++){
            if(s==wordDict[i]){
                return true;}
        }
        return false;
    }
    bool word(string s, vector<string>& wordDict, int t) {
        int n = s.size();
        
        if(s.size()==0) return true;
        if(mem.count(t-n))  return mem[t-n];
        
        for(int i=1; i<=n; i++){
            string str = s.substr(0, i);
            if(isValid(str, wordDict)){
                string temp = s.substr(i, n-i);
                if(word(temp, wordDict, t))
                    return mem[t-n+i] = true;
            }
        }
        return mem[t-n] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return word(s, wordDict, s.size());
    }
};