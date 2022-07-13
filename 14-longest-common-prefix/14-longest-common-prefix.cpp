class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int n = strs.size();
        
        if(n<=1 || strs[0].size()==0) return strs[0];
        
        int smin=INT_MAX;
        for(int i=0; i<n; i++){
            int m =strs[i].size();
            smin = min(smin, m);
        }
        
        char ans;
        
        bool check = true;
        for(int j=0; j<smin; j++){
            ans = strs[0][j];
            for(int i=1; i<n; i++){
                if(strs[i][j]!=ans) {
                    check=false;
                    break;
                }
            }
            if(check==true)
                result += ans;
        }
        return result;
    }
};