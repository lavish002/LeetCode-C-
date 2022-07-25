class Solution {
public:
    
    bool BFS(vector<vector<int>>& graph, int n, int sv, vector<int>& color){
        queue<int> q;
        q.push(sv);
        
        for(int i=0; i<n; i++){
            if(color[i]) continue;
            
            color[i]=1;
            q.push(i);
            
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(auto neighbor : graph[front]){
                    if(!color[neighbor]){
                        color[neighbor]= -color[front];
                        q.push(neighbor);
                    }

                    else if(color[neighbor] == color[front]){
                        return false;
                    }
                }
            }
            
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        // vector<vector<bool> visited(n, (n,false));
        // for(int i=0; i<n; i++){
        //     if(visited[i]==false){
                return BFS(graph, n, 0, color);
        //     }
        // }
        
    }
};

