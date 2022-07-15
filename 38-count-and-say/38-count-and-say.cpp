#include <string>
class Solution {
public:
    string ans;
    
    void say(){
        int n = ans.size();
        string temp;
        
        if(n==1) {
            ans = "11";
            return;
         }

        for(int i =0;i<n-1;){
            int count = 1;
            while(i+1 < n && ans[i+count-1]==ans[i+count]){
                count++;
            }
            temp += to_string(count);
            temp += ans[i];
            i = i + count;
        }
                
        if(ans[n-1] != ans[n-2]){
            temp += "1";
            temp += + ans[n-1];
        }
        
        ans = temp;
    }
    
    void count(int start, int end){
        if(start > end){
            return;
        }
        
        say();
        count(start+1, end);
    }
    string countAndSay(int n) {
        ans = "1";
        count(2,n);
        
        return ans;
    }
};