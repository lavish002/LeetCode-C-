#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window{};
        vector<int> ans;
        int count=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(window.empty()){
                window.push_back(i);
                count++;
            }
            else{
                
                if(window.size()==k || window.back()-window.front()==k-1){
                    window.pop_front();
                }
                while(!window.empty() && nums[i]>=nums[window.back()]){
                    window.pop_back();
                }
                window.push_back(i);
                count++;
            }
            if(count/k>=1) ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};