class Solution {
public:
    void helper(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int n){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            vector<int> temp = nums;
            //copy(nums.begin(), nums.end(), back_inserter(temp));
            ds.push_back(temp[i]);
            temp.erase(temp.begin()+ i);
            helper(temp, ds, ans, n);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        helper(nums, ds, ans, n);
        return ans;
    }
};