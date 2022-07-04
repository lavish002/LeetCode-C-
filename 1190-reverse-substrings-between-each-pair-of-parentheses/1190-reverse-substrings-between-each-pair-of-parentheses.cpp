class Solution {
public:
    void reverses(stack<char> &s){
        if(s.empty()) return;
        string str = "";
        int j=0;
        
        while(!s.empty() && s.top()!='('){
            str += s.top();
            s.pop(); 
        }
        
        if(!s.empty() && s.top()=='(')
            s.pop();
        
        //reverse(str.begin(), str.end());
        while(j<str.size()){
            s.push(str[j]);
            j++;
        }
    }
              
    string reverseParentheses(string str) {
        stack<char> s;
        int n = str.size();
        string ns="";
        int t=0;
        
        for(int i=0; i<n; i++){
            while(str[i]!=')' && i<n){
                s.push(str[i]);
                i++;
            }
            reverses(s);
        }
        
        while(!s.empty()){
            ns += s.top();
            s.pop(); t++;
        }
        
        if(str[0]=='(' || str[n-1]==')'){
            reverse(ns.begin(), ns.end());
        }
        
        if(str[0]=='(' && str[n-1]!=')'){
            reverse(ns.begin(), ns.end());
        }
        
        return ns;
    }
};