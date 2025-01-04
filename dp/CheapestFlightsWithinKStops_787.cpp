#include "../common_headers.h"

// TC: O(k * n^2)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+2, INT_MAX));
    
    for(int i=0; i<=k+1; i++) dp[src][i] = 0;
    
    for(int i=1; i<=k+1; i++){
        for(auto flight: flights){
            int cur_src = flight[0];
            int cur_dst = flight[1];
            int cur_price = flight[2];
            if(dp[cur_src][i-1] < INT_MAX)
                dp[cur_dst][i] = min(dp[cur_dst][i], dp[cur_src][i-1] + cur_price);    
            
        }
    }
    
    return dp[dst][k+1] == INT_MAX ? -1: dp[dst][k+1];
}