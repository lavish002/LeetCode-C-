class Solution {
public:
//     int length(vector<int>& nums, int ind, int pre, vector<vector<int> >& dp){
//         if(ind == nums.size()) return 0;
//         if(dp[ind][pre+1] != -1) return dp[ind][pre+1];
        
//         int ans = 0 + length(nums, ind+1, pre, dp);
        
//         if(pre==-1 || nums[pre]<nums[ind]){
//             ans = max(ans, length(nums, ind+1, ind, dp)+1);
//         }
//         return dp[ind][pre+1] = ans;
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int> > dp(n, vector<int>(n+1, -1));
//         return length(nums, 0, -1,  dp);
//     }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int ind = n-1; ind>=0; ind--){
            for(int pre=ind-1; pre>=-1; pre--){
                int ans = dp[ind+1][pre+1];
                if(pre==-1 || nums[pre]<nums[ind]){
                    ans = max(ans, dp[ind+1][ind+1]+1);
                }
                dp[ind][pre+1] = ans;
            }
        }
        return dp[0][0];
    }   
    
};