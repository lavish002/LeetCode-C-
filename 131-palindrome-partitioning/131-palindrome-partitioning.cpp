class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
    void helper(string s, vector<vector<string>>& ans, vector<string> &path, int index){
        
        if(s.size()==index){
            ans.push_back(path);
            return;
        }
        
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                helper(s, ans, path, i+1); 
                path.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(s, ans, path, 0);
        return ans;
    }
};