class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int i, lo = 0, hi = a.size()-1, mini = 1e9, maxi = -1e9, n = a.size();
        while(lo+1 < n && a[lo] <= a[lo+1]) lo++;
        while(hi-1 >= 0 && a[hi-1] <= a[hi]) hi--;
        if(lo == n-1) return 0;
        for(i = lo; i <= hi; i++) {
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }
        while(lo-1 >= 0 && a[lo-1] > mini) lo--;
        while(hi+1 <= n-1 && a[hi+1] < maxi) hi++;
        return hi-lo+1;
    }
};