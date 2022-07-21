class Solution {
    
    bool validpoint(int x, int y, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        return true;
    }

    int helper(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int n, int m) {
        
        visited[x][y]=true;

        int dir[4][2]= {{-1,0}, {0,-1}, {0, 1}, {1,0}};
        for(int i=0; i<4;i++){
            int newx= x+dir[i][0];
            int newy= y+dir[i][1];
            if(validpoint(newx, newy, n, m) && board[newx][newy] == '1' && !visited[newx][newy])
                helper(board, visited, newx, newy, n, m);
        }
        return 1;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                 if(visited[i][j] == false && grid[i][j]=='1'){
                    // char ch = board[i][j];
                    ans += helper(grid, visited, i, j, n, m);
                }
            }
        }
        return ans;
    }
};