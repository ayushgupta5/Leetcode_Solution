/*
665. Non-decreasing Array
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 

Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
*/
class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int i, n=a.size(), cnt=0;
        for(i=0;i<n-1;i++) {
            if(a[i]>a[i+1]) {
                cnt++;
                if(cnt>1) return 0;
                if(i>0 && a[i-1]>a[i+1]) a[i+1]=a[i];
            }
        }
        return 1;
    }
};