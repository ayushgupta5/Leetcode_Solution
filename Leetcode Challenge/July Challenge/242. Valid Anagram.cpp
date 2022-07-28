/*242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> A(26, 0);
        for(auto x: s) A[x-'a']++;
        for(auto x: t) A[x-'a']--;
        for(auto x: A) if(x != 0) return 0;
        return 1;
    }
};