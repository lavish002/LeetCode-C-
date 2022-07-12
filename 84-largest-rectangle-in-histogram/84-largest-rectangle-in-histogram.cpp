#include <bits/stdc++.h>
class Solution {
public:
//     watch strivers yt2 video for most optimal solution
    
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
};