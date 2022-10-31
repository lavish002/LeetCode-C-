//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool cycle(vector<int> adj[], int node, int parent, vector<int>& visited){
        visited[node] = 1;
        queue<pair<int, int>> q;
        q.push({node,parent});
        while(!q.empty()){
            int nd = q.front().first;
            int prt = q.front().second;
            q.pop();
            for(auto x: adj[nd]){
                // if(x == prt) continue;
                if(!visited[x] && x!=prt){
                    q.push({x,nd});
                    visited[x] = 1;
                }
                // else return true;
                else if( visited[x] && x != prt) return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(cycle(adj, i,-1, visited) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends