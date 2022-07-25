/*34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
class Solution {
public:
    int lowerBound(vector<int>& a, int target) {
        int lo=0, hi=a.size()-1, mid, ans=-1;
        while(lo<=hi) {
            mid=(lo+hi)>>1;
            if(a[mid]>=target) {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
    int upperBound(vector<int>& a, int target) {
        int lo=0, hi=a.size()-1, mid, ans=-1;
        while(lo<=hi) {
            mid=(lo+hi)>>1;
            if(a[mid]<=target) {
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lowerBound(nums, target);
        int idx2 = upperBound(nums, target);
        if (idx1 < nums.size() && nums[idx1] == target)  return {idx1, idx2};
        return {-1, -1};
    }
};