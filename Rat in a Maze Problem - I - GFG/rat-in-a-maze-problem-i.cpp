// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int loc[4][3] = {{0,1,0}, {1,0,1},{0,-1,2},{-1,0,3}};
    
    bool isValid( vector<vector<int>> &m, int x, int y, int n, vector<vector<int>> visited ){
        if(x>=0 && y>=0 && x<n && y<n && m[x][y]==1 && visited[x][y]==0)
            return true;
        else return false;
    }
    
    void path(vector<vector<int>> &m, vector<string>& ans, string temp, int n, int i, int j, vector<vector<int>>& visited){
        
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        //if(m[i][j] == 1){
        for(int k=0; k<4; k++){
            int x = i + loc[k][0];
            int y = j + loc[k][1];
            
            if(isValid(m, x, y, n, visited)){
                if(loc[k][2] == 0)
                    temp.append("R");
                else if(loc[k][2] == 1)
                    temp.append("D");
                else if(loc[k][2] == 2)
                    temp.append("L");
                else if(loc[k][2] == 3) 
                    temp.append("U");
                visited[x][y]=1;
                path(m, ans, temp, n, x, y, visited);
                temp = temp.substr(0, temp.length() - 1);
                visited[x][y]=false;
            }
        }
        //}
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0) {
            vector<string> temp;
            return temp;
        }
        vector<string> ans;
        vector<vector<int>> visited;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0; j<n; j++)
                temp.push_back(0);
            visited.push_back(temp);
        }
        string temp;
        visited[0][0]=1;
        path(m, ans, temp, n, 0, 0, visited);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends