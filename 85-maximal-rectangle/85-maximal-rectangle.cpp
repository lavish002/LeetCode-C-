class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int leftMost[n];
        int rightMost[n];
        
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
               leftMost[i] = 0;
            }else 
                leftMost[i] = s.top()+1;
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
               rightMost[i] = n-1;
            }else
                rightMost[i] = s.top()-1;
            s.push(i);
        }
        
        int maxA = 0;
        for(int i=0; i<n; i++){
            //cout<<rightMost[i]<<" "<<leftMost[i]<<endl;
            maxA = max(maxA, heights[i] * (rightMost[i] - leftMost[i] + 1));
        }
        return maxA;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> temp(n,0);
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]!='0'){
                    temp[j] = temp[j] + 1;
                }else
                    temp[j] = 0;
            }
            ans = max(ans, largestRectangleArea(temp));
        }
        return ans;
    }
};