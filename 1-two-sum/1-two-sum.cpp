class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int k =0;
        vector<int> x;
        while(k<size){
        for(int i=k+1; i<size; i++){
            if(nums[k]+nums[i]==target){
                x.push_back(k);
                x.push_back(i);
                break;
            }
        }
        k++;
    }
        return x;
    }
};