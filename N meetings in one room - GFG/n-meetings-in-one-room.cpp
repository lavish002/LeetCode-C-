// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> p(n,{0,0});
        
        for(int i=0; i<n; i++){
            pair<int, int> temp;
            temp.first = end[i];
            temp.second = start[i];
            p[i]= temp;
        }
        
        sort(p.begin(), p.end());
        
        int count=1;
        int j=0;
        for(int i=0; i<n-1; i++){
            //cout<<p[i].first<<" "<<p[i].second<<endl;
            if(p[j].first < p[i+1].second){
              //  cout<<p[j].first<<endl;
                count++;
                j=i+1;
            }
        }
    return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends