// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    //   bool compare(const pair<int, int>&a, const pair<int, int>&b)
    //   {
    //   return a.second<b.second;
    //   }
    
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        map<int,int, greater<int>> ab;
        for(int i=0; i<N; i++){
            ab[B[i]]+=A[i];
        }
        
        // for (auto p = ab.begin(); p != ab.end(); p--)
        // cout << "(" << p->first << ", " << p->second << ")\n";
        
        int ans=0;
        for (auto p = ab.begin(); p != ab.end(); p++)
        {
            //cout<< T<<" ";
            // if(T >= p->second){
            //   T=T-(p->second);
            //   ans = ans+ (p->first*p->second);
            // }else if(T>0 && T< p->second){
            //     ans+=(p->first*T);
            //     T=0;
            // }
            int cur = min(T, p->second);
            ans += cur * p->first;
            T -= cur;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends