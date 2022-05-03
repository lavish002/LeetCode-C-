class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0, count2=0;
        int el1=0, el2=0;
        
        for(int num:nums){
        if(count1 == 0 && el2!=num) el1 = num;
        else if(count2==0 && el1!=num) el2=num;

        if(el1 == num) count1++;
        else if(el2 == num) count2++;
        else { count1--; count2--; } 
        }
        
        vector<int> ans; 
        count1 = count2 = 0;
        for(int num:nums){
            if (el1 == num)
                count1++;
            else if (el2 == num)
                count2++;
        }
        
        if (count1 > n / 3)
            ans.push_back(el1);
        if (count2 > n / 3)
            ans.push_back(el2);
        
        return ans;
    }
};