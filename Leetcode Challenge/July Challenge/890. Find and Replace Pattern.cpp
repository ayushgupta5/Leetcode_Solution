/*890. Find and Replace Pattern
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
*/
class Solution {
public:
    bool fun(string a, string b){
        if(a.size()!=b.size()) return 0;
        unordered_map<char, char> mp;
        for(int i=0;i<a.size();i++){
            if(mp.find(a[i])==mp.end()) {  mp[a[i]]=b[i]; }
            else { if(b[i]!=mp[a[i]]) return 0; }
        }
        return 1;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        for(int i=0;i<words.size();i++){
            if(fun(pattern, words[i]) && fun(words[i], pattern)){
                v.push_back(words[i]);
            }
        }
        return v;
    }
};




