class Solution {
public:
bool checkPalindrom(string str){
int n=str.length();
for(int i=0;i<n/2;i++){
if( str[i] != str[n-i-1] )
return false;
}
return true;
}
string longestPalindrome(string s) {
if(s.size()==1) return s;
string temp="";
int maxsize=0;
string ans="";
int len = s.length();
for(int i=0;i<len;i++){
for(int n=1;n<=len-i;n++){
temp = s.substr(i, n);
if(temp.size()>maxsize && checkPalindrom(temp)) {
maxsize=temp.length();
ans = temp;
}
}
}
return ans;
}
};