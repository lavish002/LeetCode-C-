class Solution {
public:
void helper(string s, vector<vector<string>> ans, vector<string> temp, int n){
if(s.size()==n)
ans.push_back(temp);
temp.push_back(s[0]);
if(ispalidrome(temp))
helper(s, ans, temp, n+1);
for(int i=n+1; i<s.size(); i++){
string str= temp[n]+s[i];
if(ispalidrome(str))
temp.push_back(str);
}
}
vector<vector<string>> partition(string s) {
vector<vector<string>> ans;
vector<string> temp;
helper(s, ans, temp,0);
}
};