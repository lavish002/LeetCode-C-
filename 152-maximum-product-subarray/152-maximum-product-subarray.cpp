class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curMin=1, curMax=1;
        // int n = nums.size();
        for(auto n:nums){
            if(n==0){
                curMin=1; curMax = 1;
                continue;
            }
            int temp = curMax;
            curMax = max({n*curMax, n*curMin, n});
            curMin = min({n*temp, n*curMin, n});
            res = max(res, curMax);
        }
        return res;
    }
};