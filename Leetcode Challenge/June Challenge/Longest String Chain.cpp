/*
1048. Longest String Chain
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.
*/
//Striver
class Solution {
public:
    bool ok(string &a, string &b) {
        if(a.size() != 1 + b.size()) return 0;
        int i = 0, j = 0;
        while(i < a.size()) {
            if(a[i] == b[j]) {
                i++; j++;
            }
            else i++;
        }
        return i == a.size() && j == b.size();
    }
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& a) {
        int i, prev, n = a.size(), ans = 1;
        sort(a.begin(), a.end(), comp);
        vector<int> dp(n, 1);
        for(i=0; i<n; i++) {
            for(prev=0; prev<i; prev++) {
                if(ok(a[i], a[prev]) && dp[i] < (1 + dp[prev])) {
                    dp[i] = 1 + dp[prev];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


//Ayushi Sharma Youtube Video Reference
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int i, n = words.size(), j, ans = 1, wordValue, predValue;
        vector<unordered_set<string>> W(17);
        for(auto word: words) 
            W[word.size()].insert(word);
        unordered_map<string, int> dp;
        for(i=16; i>0; i--) {
            if(W[i-1].size() == 0) continue;
            for(auto word: W[i]) {
                wordValue = dp[word] ? dp[word] : 1;
                for(j=0; j<word.size();j++) {
                    string pred = word.substr(0, j) + word.substr(j+1);
                    predValue = dp[pred]?dp[pred]:1;
                    if(W[i-1].find(pred) != W[i-1].end() && wordValue >= predValue) {
                        dp[pred] = wordValue + 1;
                        ans = max(ans, wordValue + 1);
                    }
                }
            }
        }
        return ans;
    }
};

