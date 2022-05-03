class Solution {
public:
    int uniquePaths(int m, int n) {
        int count = m+n-2;
        int r = m-1;
        double res=1;
        
        for(int i=1; i<=r; i++)
            res = res*(count-r+i)/i;
        
        return (int)res;
    }
};