class Solution {
    vector<int> kmpProcess(string needle){
        int n =needle.size();
        vector<int>  lps(n,0);
        for(int i=1, len=0; i<n;){
            if (needle[i]==needle[len]){
                lps[i++] = ++len;
            }else if(len){
                len = lps[len-1];
            }else{
                lps[i++] = 0;
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(!n) return 0;
        
        vector<int> lps = kmpProcess(needle);
        for(int i=0, j=0; i<m; ){
            if(haystack[i]==needle[j]){
                i++; j++;
            }
            if(j==n)
                return i-j;
            if(i<m && haystack[i]!=needle[j]){
                j ? j = lps[j-1] : i++;
            }
        }
        return -1;
    }
    
    int CommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // if(m<n) longestCommonSubsequence(text2, text1);
        int maxi = 0;
        int len=0;
        for(int pos=0,i=0; pos<n; pos++){
           
            // cout<<text2.substr(pos,1)<<" ";
            int ind = strStr(text1.substr(i), text2.substr(pos,1));
            if(ind != -1){
                // cout<<endl<<text2.substr(pos,1)<<" ";
                i = ind+1;
                len++;
                if(len>maxi) maxi = len;
                
            }
            else len = 0;
            // cout<<endl;
            
        }
        return maxi;
    }
    
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
    }
};
