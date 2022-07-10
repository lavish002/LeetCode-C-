//my code not working
class Solution {
public:
​
int valid[8][2] = {{1,2},{2,1},{1,-2},{-1,2},{-2,1},{2,-1},{-1,-2},{-2,-1}};
//     bool isvalid( vector<string> ds, int n, int x, int y){
//         if(x<0 || x>=n || y<0 || y>=n)  return false;
//         if(ds[y] != "") return false;
//         for(int i=0; i<n; i++){
//             if(ds[i]!="" || ds[i]!=ds[y]){
//                 if(ds[i][x] == "Q")
//                     return false;
//             }
//         }
//         while(x!=-1 || y!=-1){
//             x--;y--;
//             if(ds[x]!=""){
//                 if(ds[x][y] == "Q")
//                     return false;
//                 if(ds[y]!="" && ds[y][x]=="Q")
//             }
//         }