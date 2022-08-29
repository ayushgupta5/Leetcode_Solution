/*200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]                            Output: 1
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]                            Output: 3
*/
class Solution {
public:
    void dfs(vector<vector<char>> &A, int n, int m, int i, int j){
        if(i<0||i>=n||j<0||j>=m||A[i][j]!='1') return ;
        A[i][j]='0';
        dfs(A,n,m,i,j-1);
        dfs(A,n,m,i,j+1);
        dfs(A,n,m,i+1,j);
        dfs(A,n,m,i-1,j);
    }
    int numIslands(vector<vector<char>>& a) {
        int ans = 0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='1'){
                    ans++;    dfs(a, a.size(), a[0].size(), i, j);
                }
            }
        }
        return ans;
    }
};


