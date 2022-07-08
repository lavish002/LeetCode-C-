class Solution {
public:
    vector<vector<int>> helper(vector<int>& arr, int n) {
        vector<vector<int>> ans;
        
        if(n==0){
            vector<int> temp={};
            ans.push_back(temp);
            return ans;
        }
        //s+=arr[N-1];
        ans = helper(arr, n-1);
        int t = ans.size();
        for(int i=0; i<t; i++){
            vector<int> temp = ans[i];
            temp.push_back(arr[n-1]);
            sort(temp.begin(), temp.end());
            if( find(ans.begin(), ans.end(), temp) == ans.end() )
                ans.push_back(temp);
        }
        
        return ans;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        // Write Your Code here
        vector<vector<int>> ans = helper(nums, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};