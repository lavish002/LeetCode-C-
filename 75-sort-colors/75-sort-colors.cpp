class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1=0, p2=nums.size()-1;
        
        for(int i=0; i<=p2; i++){
            if(nums[i]==0 ){
            swap(nums[p1],nums[i]); p1++;
            }
            else if(nums[i]==2){
            swap(nums[p2],nums[i]); p2--; i--;
            }
        }
//             if(nums[p1]==0 && p1!=p3)
//                 p1++;
//             if(nums[p3]==2 && p3!=p1)
//                 p3--;   
        
    }
};