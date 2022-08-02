/*378. Kth Smallest Element in a Sorted Matrix
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Input: matrix = [[-5]], k = 1
Output: -5
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int i, n=a.size(), lo=a[0][0], hi=a[n-1][n-1], mid, cnt, ans=0;
        while(lo<=hi) {
            mid=(lo+hi)>>1;
            cnt=0;
            for(i=0;i<n;i++) {
                cnt += upper_bound(a[i].begin(), a[i].end(), mid)-a[i].begin();
            }
            if(cnt>=k) {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};



