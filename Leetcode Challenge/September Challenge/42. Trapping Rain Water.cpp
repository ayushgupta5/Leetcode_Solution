/*42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Input: height = [4,2,0,3,2,5]
Output: 9        */
class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size(), ans = 0, lo = 0, hi = n-1, loMax = 0, hiMax = 0;
        while(lo <= hi) {
            if(a[lo] < a[hi]) {
                if(loMax < a[lo]) loMax = a[lo];
                else ans += (loMax - a[lo]);
                lo++;
            }
            else {
                if(hiMax < a[hi]) hiMax = a[hi];
                else ans += (hiMax - a[hi]);
                hi--;
            }
        }
        return ans;
    }
};



