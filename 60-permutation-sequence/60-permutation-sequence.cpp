class Solution {
public:
    
    // strivers : https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=56
    
    
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1; i<n; i++){
            fact = i* fact;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans="";
        k = k-1;
        while(true){
            ans =  ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0){
                break;
            }
            k = k%fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};