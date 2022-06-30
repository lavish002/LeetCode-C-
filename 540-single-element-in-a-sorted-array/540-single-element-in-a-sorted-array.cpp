class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size()-1;
        int left=0, right=n;
        int ans=-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(mid%2==1){
                if(mid!=0 && nums[mid-1]==nums[mid])
                    left = mid+1;
                else if(nums[mid+1]==nums[mid])
                    right = mid-1;
                else{
                    ans=nums[mid];
                    break;
                }
            }
            else{
                if(nums[mid+1]==nums[mid])
                    left = mid+1;
                else if(mid!=0 && nums[mid-1]==nums[mid])
                    right = mid-1;
                else{
                    ans=nums[mid];
                    break;
                }
            }
        }
        return ans;
    }
};