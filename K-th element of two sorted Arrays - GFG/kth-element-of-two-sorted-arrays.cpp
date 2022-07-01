// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int m, int n, int k)
    {
        if(m>n) return kthElement(nums2,nums1,n,m,k); 
        //ensuring that binary search happens on minimum size array
        
        int low=0,high=m,medianPos=k;
        while(low<=high) {
            int cut1 = (low+high)>>1;
            if(cut1>medianPos){
                high = cut1-1;
                continue;
            }
            int cut2 = medianPos - cut1;
            if(cut2>n){
                low = cut1+1;
                continue;
            }
            int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)? INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1) {
                return max(l1,l2);
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends