// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

struct prop{
    int value;
    int weight;
    double ratio;
};


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        prop a[n];
        for(int i=0; i<n; i++){
            a[i].value = arr[i].value;
            a[i].weight = arr[i].weight;
            a[i].ratio = (double) arr[i].value/ (double) arr[i].weight;
        }
        
        sort(a, a+n, [] (prop a, prop b) {
            return a.ratio > b.ratio;
        });
        
        double ans=0;
        int wgt=0;
        for(int i=0; i<n; i++){
            if((wgt+a[i].weight)<=W){
                wgt += a[i].weight;
                ans += a[i].value;
            }else{
                ans += (W-wgt)*a[i].ratio;
                wgt = W;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends