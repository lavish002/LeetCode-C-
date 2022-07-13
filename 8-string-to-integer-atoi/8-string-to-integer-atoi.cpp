class Solution {
public:
    int myAtoi(string s) {
        int long long ans=0;
        char ch;
        int i=0;
        
        while(s[i]==' '){
            i++;
        }
        
        if(s[i]=='+' || s[i]=='-'){
                ch=s[i];
            i++;
        }
        for(i ;i<s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                ans = ans*10 + (s[i]-'0');
                
                if(ch=='-'){
                    if(-ans<=INT_MIN)
                        return INT_MIN;
                }
                else if(ans >= INT_MAX)
                    return INT_MAX;
            }
            else{
                break;
            }
        }
        if(ch=='-'){
            return -ans;
        }
       return ans;    
    }
};