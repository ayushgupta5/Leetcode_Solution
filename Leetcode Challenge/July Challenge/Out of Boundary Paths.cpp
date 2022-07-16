/*
576. Out of Boundary Paths
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/
class Solution {
public:
    int f(int i, int j, int &n, int &m, int maxMove, int &M, vector<vector<vector<int>>> &dp) {
        if(maxMove < 0) return 0;
        if(i < 0 || j < 0 || i >= n || j >= m) return 1;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        int res = 0;
        int a = f(i + 1, j, n, m, maxMove - 1, M, dp) % M;
        res += a; res %= M;
        int b = f(i - 1, j, n, m, maxMove - 1, M, dp) % M;
        res += b; res %=M;
        int c = f(i, j + 1, n, m, maxMove - 1, M, dp) % M;
        res += c; res %= M;
        int d = f(i, j - 1, n, m, maxMove - 1, M, dp) % M;
        res += d; res %= M;
        return dp[i][j][maxMove] = res % M;
    }
    int findPaths(int n, int m, int maxMove, int r, int c) {
        int cnt=0, M=1e9+7;
        vector<vector<vector<int>>> dp(51, vector<vector<int>> (51, vector<int> (51, -1)));
        return f(r, c, n, m, maxMove, M, dp);
    }
};