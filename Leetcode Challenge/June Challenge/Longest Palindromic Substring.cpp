/*
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
class Solution {
public:
    string substr(string &s, int lo, int hi) {
        string ans = "";
        for(int i = lo; i <= hi; i++) {
            ans += s[i];
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int gap, i, j, n=s.size(), lo, hi;
        string ans="";
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(gap=0;gap<n;gap++) {
            for(i=0, j=gap;i<n, j<n;i++,j++) {
                if(gap==0) {
                    dp[i][j]=1; lo=i, hi=j;
                }
                else if(gap==1) {
                    if(s[i]==s[j]) {
                        dp[i][j]=1; lo=i; hi=j;
                    }
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]==1) {
                        dp[i][j]=1; lo=i; hi=j;
                    }
                }
            }
        }
        return ans=substr(s, lo, hi);
    }
};