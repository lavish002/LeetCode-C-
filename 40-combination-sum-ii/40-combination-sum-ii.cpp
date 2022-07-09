class Solution {
public:
    
    void helper (vector<vector<int>>& ans, vector<int>& arr, int ind, int n, int target, vector<int>& temp) {

        if(ind == arr.size()){    
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target>=arr[ind] && (n==ind || arr[ind]!=arr[ind-1])){
            n=ind;
            temp.push_back(arr[ind]);
            helper(ans, arr, ind+1, n+1, target-arr[ind], temp);
            
            temp.pop_back();
        }
        helper(ans, arr, ind+1, n, target, temp);
}
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        //int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, nums,0, 0, target, temp);
        return ans;
    }
    
};