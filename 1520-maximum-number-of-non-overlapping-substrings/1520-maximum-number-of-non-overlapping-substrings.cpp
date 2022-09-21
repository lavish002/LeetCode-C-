class Solution {
public:
    int checkSubstr(string &s, int i, vector<int> &l, vector<int> &r) {
    int right = r[s[i] - 'a'];
    for (auto j = i; j <= right; ++j) {
        if (l[s[j] - 'a'] < i)
            return -1;
        right = max(right, r[s[j] - 'a']);
    }
    return right;
}
vector<string> maxNumOfSubstrings(string s) {
    vector<int> l(26, INT_MAX), r(26, INT_MIN);
    vector<string> res;
    for (int i = 0; i < s.size(); ++i) {
        l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
        r[s[i] - 'a'] = i;
    }
    int right = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (i == l[s[i] - 'a']) {
            int new_right = checkSubstr(s, i, l, r);
            if (new_right != -1) {
                if (i > right)
                    res.push_back("");                     
                right = new_right;
                res.back() = s.substr(i, right - i + 1);
            }
        }
    }
    return res;
}
};


// bool findstr(string s, char c, int st, int ed){
//         for(int i=0; i<s.size(); i++){
//             if(i<=st || i>=ed){
//                 if(s[i]==c) return false;
//             }
//         }
//         return true;
//     }
    
//     bool checkstr(string s, int sp, int ep){
//         int i = sp+1;
//         for(; i<ep; i++){
//             char c = s[i];
//             if(findstr(s, c, sp, ep) == false) return false;
//         }
//         return true;
//     }
    
//     vector<string> maxNumOfSubstrings(string s) {
//         int n = s.size();
//         vector<string> ans;
//         int prev=-1;
//         string temp2;
//         for(int i=0; i<n;){
//             int st=i;
//             string temp;
//             char c = s[i];
//             while(s[i]==c){
//                 temp += s[i];
//                 temp2 += s[i];
//                 i++;
//             }

//             if(findstr(s, c, st-1, i)){
//                 ans.push_back(temp);
//                 prev = i-1;
//                 temp2="";
//             }else{
//                 if(checkstr(s, prev, i)){
//                     prev = i-1;
//                     ans.push_back(temp2);
//                     temp2="";
//                 }
//             }
//         }
//         return ans;
//     }