/*
322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
*/
class Solution {
public:
    int dp[10001];
    int f(vector<int> &coins, int n, int amt) {
        if(amt == 0) return 0;
        if(dp[amt] != -1) return dp[amt];
        int res=1e9;
        for(int i=0;i<n;i++) {
            if(coins[i] <= amt) {
                int sub_res = f(coins, n, amt-coins[i]);
                if(sub_res != 1e9) res = min(res, sub_res+1);
            }
        }
        return dp[amt] = res;
    }
    int coinChange(vector<int>& coins, int amt) {
        memset(dp, -1, sizeof(dp));
        int n = coins.size(), var = f(coins,n,amt);
        return var == 1e9 ? -1 : var;
    }
};