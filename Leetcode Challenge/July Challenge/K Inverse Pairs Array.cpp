/*
629. K Inverse Pairs Array
For an integer array nums, an inverse pair is a pair of integers [i, j] 
where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, 
return the number of different arrays consist of numbers from 1 to n 
such that there are exactly k inverse pairs. 
Since the answer can be huge, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
Example 2:

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
 

Constraints:

1 <= n <= 1000
0 <= k <= 1000
*/
class Solution {
public:
    /*
    int dp[1001][1001];
    int M=1e9+7;
    int f(int n, int k) {
        if(k==0) return 1;
        if(n==0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        int ans=0;
        for(int i=0;i<=min(n-1, k);i++) {
            ans+=f(n-1, k-i);
            ans%=M;
        }
        return dp[n][k] = ans%M;
    }
    */
    int kInversePairs(int n, int k) {
        int dp[1001][1001], M=1e9+7;
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                if(j==0) dp[i][j]=1;
                else {
                    for(int ii=0;ii<=min(i-1, j);ii++) {
                        dp[i][j] += dp[i-1][j-ii];
                        dp[i][j] %= M;
                    }
                }
            }
        }
        return dp[n][k];
    }
};