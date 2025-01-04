// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
 

// Constraints:
// 1 <= n <= 45

#include "../common_headers.h"

// Sol 2: DP with space compression
// TC: O(n)
// SC: O(1)
int climbStairs(int n) {
    if(n <= 2) return n;
    int prev2 = 1, prev1 = 2, cur;
    for(int i=3; i<=n; i++){
        cur = prev2 + prev1;
        prev2 = prev1;
        prev1 = cur;
    }
    
    return cur;
}

// Sol 1: DP
// TC: O(n)
// SC: O(n)
int climbStairs1(int n) {
    vector<int> dp(n+1, a1);
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    cout << climbStairs(3) << endl;
    //  vector<int> dp(3, 1);
}