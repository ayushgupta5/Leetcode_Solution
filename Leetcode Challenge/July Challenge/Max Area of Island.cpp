/*
695. Max Area of Island
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/
class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>> &a) {
        if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || a[i][j]==0) return 0;
        a[i][j]=0;
        return 1+dfs(i+1,j,n,m,a)+dfs(i-1,j,n,m,a)+dfs(i,j+1,n,m,a)+dfs(i,j-1,n,m,a);
    }
    int maxAreaOfIsland(vector<vector<int>>& a) {
        int i, j, n=a.size(), m=a[0].size(), ans=0;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(a[i][j]==1) {
                    ans=max(ans, dfs(i,j,n,m,a));
                }
            }
        }
        return ans;
    }
};