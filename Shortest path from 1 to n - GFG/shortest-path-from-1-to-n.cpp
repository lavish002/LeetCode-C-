//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

// class Solution{  
//     int step(int n, vector<int> &dp){
//         if(n==1) return dp[n] = 0;
//         else if(n==2 || n==3) return dp[n] = 1;
        
//         if(dp[n]!=-1) return dp[n];
        
//         int t1=INT_MAX;
//         int t2 = step(n-1, dp)+1;
//         if(n%3==0) t1 = step(n/3, dp)+1;
        
//         return dp[n] = min(t1,t2);
//     }
// public:
//     int minimumStep(int n){
//         vector<int> dp(n+1,-1);
//         return step(n, dp);
//     }
// };

class Solution{  
public:
    int minimumStep(int n){
        int count=0;
        
        for(int i =n ; i>1; i--){
            if(i%3==0){
                count++;
                i=i/3;
                i++;
            }
            else
                count++;
        }
        return count;
    }
};



//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends