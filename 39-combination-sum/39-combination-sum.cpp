class Solution {
  public:
    void helper(vector<vector<int>>& ans, vector<int>& arr, int ind, int n, int target, vector<int>& temp) {
        if(ind==n){
            if(target==0)
                ans.push_back(temp);
            return;
        }
        if(target>=arr[ind]){
            temp.push_back(arr[ind]);
            helper(ans, arr, ind, n, target-arr[ind], temp);
            temp.pop_back();
        }
        helper(ans, arr, ind+1, n, target, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, nums,0, n, target, temp);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
};