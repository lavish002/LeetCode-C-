class Solution {
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        for(int i=0; i<n1; i++) dp[0][n2] = 0;
        for(int i=0; i<n2; i++) dp[n1][0] = 0;
        
        for(int ind1=1; ind1<=n1; ind1++){
            for(int ind2=1; ind2<=n2; ind2++){
                int take = INT_MIN;
                if(text1[ind1-1]==text2[ind2-1])
                    take = 1+dp[ind1-1][ind2-1];
                
                int notTake = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                dp[ind1][ind2] = max(take, notTake);
            }
        }
        
        return dp[n1][n2];
    }
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1; 
        reverse(s2.begin(), s2.end());
        return longestCommonSubsequence(s1, s2);
    }
};