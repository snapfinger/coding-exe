#include "../common_headers.h"

// TC: O(n)
// SC: O(1)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int cur, prev1 = cost[1], prev2 = cost[0];
    
    for(int i=2; i<cost.size(); i++){
        cur = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = cur;
    }
    
    return min(prev1, prev2);
}

// TC: O(n)
// SC: O(n)
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, 1);
    
    for(int i=0; i<cost.size(); i++){
        
        if(i < 2) dp[i] = cost[i];
        else{
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);                
        }
    }
    
    return min(dp[n-1], dp[n-2]);
}