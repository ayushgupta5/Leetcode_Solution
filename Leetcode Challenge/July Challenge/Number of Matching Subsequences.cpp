/*
792. Number of Matching Subsequences
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& a) {
        int i, n = s.size(), j, ind = -1, ans = 0;
        vector<vector<int>> A(26);
        for(i=0; i<n; i++) A[s[i]-'a'].push_back(i);
        for(const auto &x: a) {
            ind = -1; bool found = 1;
            for(char ch: x) {
                auto it = upper_bound(A[ch-'a'].begin(), A[ch-'a'].end(), ind);
                if(it == A[ch-'a'].end()) found = 0;
                else ind = *it;
            }
            if(found) ans++;
        }
        return ans;
    }
};