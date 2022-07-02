class Solution {
public:
    bool isValid(string s) {
        int n= s.size();
        stack<char> p;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                p.push(s[i]);
            else if( !p.empty() && ((s[i]==')' && p.top()=='(') || (s[i]=='}' && p.top()=='{') || (s[i]==']' && p.top()=='[')) ){
                p.pop();
            }else return false;
        }

        if(p.empty()==true)
            return true;
        else return false;
    }
};