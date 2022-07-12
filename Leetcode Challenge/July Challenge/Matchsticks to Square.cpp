/*
473. Matchsticks to Square
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
You want to use all the matchsticks to make one square. 
You should not break any stick, but you can link them up, 
and each matchstick must be used exactly one time.
Return true if you can make this square and false otherwise.


Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
*/
class Solution {
public:
    bool f(int ind, int s1, int s2, int s3, int s4, vector<int> &a) {
        if(ind == a.size()) {
            return s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0;
        }
        if(a[ind] <= s1) {
            s1 -= a[ind];
            if(f(ind + 1, s1, s2, s3, s4, a)) return 1;
            s1 += a[ind];
        }
        if(a[ind] <= s2) {
            s2 -= a[ind];
            if(f(ind + 1, s1, s2, s3, s4, a)) return 1;
            s2 += a[ind];
        }
        if(a[ind] <= s3) {
            s3 -= a[ind];
            if(f(ind + 1, s1, s2, s3, s4, a)) return 1;
            s3 += a[ind];
        }
        if(a[ind] <= s4) {
            s4 -= a[ind];
            if(f(ind + 1, s1, s2, s3, s4, a)) return 1;
            s4 += a[ind];
        }
        return 0;
    }
    bool makesquare(vector<int>& a) {
        if(a.size() < 4) return 0;
        int sum = 0, side;
        for(auto x: a) sum += x;
        if(sum%4 != 0) return 0;
        side = sum / 4;
        sort(a.rbegin(), a.rend());
        return f(0, side, side, side, side, a);
    }
};