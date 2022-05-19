/*
581. Shortest Unsorted Continuous Subarray
Given an integer array nums, you need to find one continuous subarray 
that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.
Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int i, lo = 0, hi = a.size()-1, mini = 1e9, maxi = -1e9, n = a.size();
        while(lo+1 < n && a[lo] <= a[lo+1]) lo++;
        while(hi-1 >= 0 && a[hi-1] <= a[hi]) hi--;
        if(lo == n-1) {
            return 0;
        }
        for(i = lo; i <= hi; i++) {
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }
        while(lo-1 >= 0 && a[lo-1] > mini) lo--;
        while(hi+1 <= n-1 && a[hi+1] < maxi) hi++;
        return hi-lo+1;
    }
};