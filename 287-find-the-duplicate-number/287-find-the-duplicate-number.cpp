class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int temp = nums[0];
        nums[0] *= -1;
        while(nums[temp]>0){
            int r = temp;
            temp = nums[temp];
            nums[r] *= -1;
        }
        return temp;
    }
};