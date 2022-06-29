// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int, int>> p(n,{0,0});
        
        for(int i=0; i<n; i++){
            pair<int, int> temp;
            temp.first = arr[i];
            temp.second = dep[i];
            p[i]= temp;
        }
        
        sort(p.begin(), p.end());
        
        int count=0;
        vector<int> store;
        store.push_back(p[0].second);
        //cout<<p[0].first<<" "<<p[0].second<<endl;
        //cout<<store[count]<<" "<<"1"<<endl;
        
        for(int i=0; i<n-1; i++){
            //cout<<p[i+1].first<<" "<<p[i+1].second<<endl;
            bool check=false;
            for(int j=count; j>=0; j--){
                if(store[j] < p[i+1].first){
                    store[j]=p[i+1].second;
                    check=true;
                    break;
                }
            }
            if(check==false){
                count++;
                store.push_back(p[i+1].second);
                //cout<<store[count]<<" "<<count+1<<endl;
            }
        }
        return count+1;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends