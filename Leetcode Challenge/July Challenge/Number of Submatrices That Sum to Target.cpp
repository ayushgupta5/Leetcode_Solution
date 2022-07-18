/*
1074. Number of Submatrices That Sum to Target
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.


Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int k) {
        int i, j, n = a.size(), m = a[0].size(), ans = 0, c1, c2, sum, row;
        for(i=0; i<n; i++) {
            for(j=1; j<m; j++) {
                a[i][j]+=a[i][j-1];
            }
        }
        for(c1=0; c1<m; c1++) {
            for(c2=c1; c2<m; c2++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                sum = 0;
                for(row=0; row<n; row++) {
                    sum += (a[row][c2]) - (c1>0 ? a[row][c1-1] : 0);
                    ans += mp[sum-k];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};