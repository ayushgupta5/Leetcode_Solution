/*
583. Delete Operation for Two Strings
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/
class Solution {
public:
    int f(string &a, string &b, int n, int m, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1] == b[m-1]) return dp[n][m] = 1 + f(a, b, n-1, m-1, dp);
        int x = f(a, b, n-1, m, dp);
        int y = f(a, b, n, m-1, dp);
        return dp[n][m] = max(x, y);
    }
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size(), ans=n+m;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return ans-2*f(a, b, n, m, dp);
    }
};