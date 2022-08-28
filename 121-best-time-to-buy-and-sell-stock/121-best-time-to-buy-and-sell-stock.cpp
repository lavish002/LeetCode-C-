class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int a=0;
        for(int i=1; i<n; i++){
            int temp = prices[i]-prices[a];
            if(temp > maxi)
                maxi = temp;
            else if(temp<0) a = i;
        }
        return maxi;
    }
};