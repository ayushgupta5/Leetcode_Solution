/*
647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
class Solution {
public:
    int dp[1001][1001];
    int f(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return 0;
            i++; j--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        memset(dp, -1, sizeof(dp));
        int i, j, n=s.size(), ans=0;
        for(i=0;i<n;i++) {
            for(j=i;j<n;j++) {
                ans += f(s, i, j);
            }
        }
        return ans;
    }
};