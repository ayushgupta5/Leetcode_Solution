/*
135. Candy
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/
class Solution {
public:
    /*
        ratings[] = 12 4 3 11 34 34 1 67
        l2r[] =      1 1 1 1  1  1  1 1 
        l2r[] =      1 1 1 2  3  1  1 2 

        ratings[] = 12 4 3 11 34 34 1 67
        r2l[] =      1 1 1 1  1  1  1 1 
        r2l[] =      3 2 1 1  1  2  1 1 

                l2r[] =      1 1 1 2 3 1 1 2 
                r2l[] =      3 2 1 1 1 2 1 1 
        ans = max(l2r,r2l) = 3+2+1+2+3+2+1+2=16
    */
    int candy(vector<int>& a) {
        int i, ans = 0, n = a.size();
        vector<int> l2r(n, 1), r2l(n, 1);
        for(i = 1; i < n; i++) {
            if(a[i] > a[i-1]) l2r[i] = l2r[i - 1] + 1;
        }
        for(i = n - 2; i >= 0; i--) {
            if(a[i] > a[i + 1]) r2l[i] = r2l[i + 1] + 1;
        }
        for(i = 0; i < n; i++) {
            ans += max(l2r[i], r2l[i]);
        }
        return ans;
    }
};