class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};
    
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         vector<int> nums3;
//         for(int i=0;i<m; i++)
//             nums3.push_back(nums2[i]);
        
//         sort(nums2.begin(), nums2.end());
//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             int low=0, high=m;
//             while(low <= high){
//                 int mid = low+(high-low)/2;
//                 if(nums2[mid]<nums1[i]) low = mid+1;
//                 else if(nums2[mid]>nums1[i]) high = mid-1;
//                 else{
//                     low = mid; break;
//                 }
//             }
//             bool temp = false;
//             for(int j=low; j<m; j++){
//                 if(nums2[low]<nums2[j]){
//                     ans.push_back(nums2[j]);
//                     temp = true;
//                     break;
//                 }
//             }
//             if(temp==false){
//                 ans.push_back(-1);
//             }
//         }
//         return ans;
//     }