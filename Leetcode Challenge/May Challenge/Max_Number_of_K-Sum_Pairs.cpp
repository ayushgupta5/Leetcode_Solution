class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        int lo = 0, hi = a.size() - 1, ans = 0;
        sort(a.begin(), a.end());
        while(lo < hi && a[lo] < k) {
            if(a[lo] + a[hi] < k) lo++;
            else if(a[lo] + a[hi] > k) hi--;
            else {
                lo++; hi--; ans++;
            }
        }
        return ans;
    }
};