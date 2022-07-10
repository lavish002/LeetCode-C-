// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isValid(bool graph[101][101], vector<int> col, int fil, int edge, int n){
    for(int i=0; i<n; i++){
        if(graph[edge][i] == true){
            if(col[i]==fil)
                return false;
        }
    }
    return true;
}


bool coloring(bool graph[101][101], int m, int n, vector<int>& col){
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            
            if(graph[i][k]==true){
                if(col[i]==-1){
                    for(int j=0; j<m; j++){
                        if(isValid(graph, col, j, i, n)){
                            col[i]=j;
                            if(coloring(graph, m, n, col))
                                return true;
                            else col[i]=-1;
                        }
                    }
                    return false;
                }
            }
            
        }
    }
    return true;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> col(n,-1);
    return coloring(graph, m , n, col);
}






// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends