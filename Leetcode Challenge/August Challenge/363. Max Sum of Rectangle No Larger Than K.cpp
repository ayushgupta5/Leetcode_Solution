/*363. Max Sum of Rectangle No Larger Than K
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Input: matrix = [[2,2,-1]], k = 3
Output: 3
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int i, j, ind, n=a.size(), m=a[0].size(), ans=-1e9, currSum;
        for(ind=0; ind<m; ind++) {
            vector<int> sums(n);
            for(j=ind; j<m; j++) {
                for(i=0; i<n; i++) sums[i] += a[i][j];
                set<int> st={0};
                currSum=0;
                for(auto x: sums) {
                    currSum += x;
                    auto it = st.lower_bound(currSum - k);
                    if(it != end(st)) ans=max(ans, currSum - *it);
                    st.insert(currSum);
                }
            }
        }
        return ans;
    }
};

