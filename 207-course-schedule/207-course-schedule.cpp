class Solution {
    bool print(int** edges, int n, bool* visited,  bool* dfsvis, int sv){
        visited[sv] = true;
        dfsvis[sv] = true;
        for(int i=0; i<n; i++){
            if(i==sv)   continue;
            if(edges[sv][i]==1){
                if(dfsvis[i]){
                    return false;
                }
                if(visited[i]) continue;
                bool ans = print(edges, n, visited, dfsvis, i);
                // dfsvis[i] = false;
                if(ans == false)
                    return false;
            }
        }
        dfsvis[sv] = false;
        
        
        return true;
    }
    
    // bool Bfs(int** edge, int n, bool* visited, int sv){
    //     queue<int> q;
    //     q.push(sv);
    //     visited[sv]=true;
    //     
    //     while(!q.empty()){
    //         int front = q.front();
    //         q.pop();
    //         for(int i=0; i<n; i++){
    //             if(i==front){
    //                 continue;
    //             }
    //             if(edge[front][i]==1){
    //                 if(visited[i])
    //                     return false;
    //                 q.push(i);
    //                 visited[i]=true;
    //             }
    //         }
    //     }
    //     
    //     for(int i=0; i<n; i++){
    //         if(visited[i]==false){
    //            return false;
    //         }
    //     }
    //     
    //     return true;
    // }
      
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        int e = prerequisites.size();
        
        if(n==1 || e==0) return true;

        int** edge = new int*[n];
        for(int i=0; i<n; i++){
            edge[i]=new int[n];
            for(int j=0; j<n; j++){
                edge[i][j]=0;
            }
        }
        for(int i=0; i<e; i++){
            int f = prerequisites[i][0];
            int s = prerequisites[i][1];
            if(f==s) return false;
            edge[f][s]=1;
        }
        bool* visited = new bool[n]{false};
        bool* dfsvis = new bool[n]{false};
        bool ans = false;
        
        
        
         // ans = print(edge, n, visited, dfsvis, prerequisites[0][0]);
//         if(ans = false) return false;
        for(int i=0; i<n; i++){
            if(visited[i]==false){
                bool ans = print(edge, n, visited, dfsvis, i);
                if(ans == false) return false;
            }
        }
        
        
        return true;
    }
};