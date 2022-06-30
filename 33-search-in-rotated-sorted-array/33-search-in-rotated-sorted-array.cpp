class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        while(left<= right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while(left <= right){
            int mid = left+(right-left)/2;
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[left] <= nums[mid]){
                int temp = binarySearch(nums, target, left, mid);
                if(temp == -1){
                    left=mid+1;
                }else
                    return temp;
            }
            else{
                int temp = binarySearch(nums, target, mid, right);
                if(temp == -1){
                    right=mid-1;
                }else
                    return temp;
            }
        }
        return -1;
    }
};