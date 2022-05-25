/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int i, n = s.size(), ans = 0, open = 0, close = 0;
        for(i=0; i<n; i++) {
            if(s[i] == '(') open++;
            else close++;
            if(open == close) ans = max(ans, (open + close));
            else if(close > open) open = close =0;
        }
        open = close = 0;
        for(i=n-1; i>=0; i--) {
            if(s[i] == '(') open ++;
            else close++;
            if(open == close) ans = max(ans, (open + close));
            else if(open > close) open = close = 0;
        }
        return ans;
    }
};