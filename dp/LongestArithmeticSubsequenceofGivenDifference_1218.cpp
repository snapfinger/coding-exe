#include "../common_headers.h"

// Sol 1: DP + Hash map3
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    unordered_map<int, int> dp;
    int rst = 1;

    for(auto num: arr){
        dp[num] = dp[num - difference] + 1;    
        rst = max(rst, dp[num]);        
    }

    return rst;

}

// Sol 0: DP
// TC: O(n^2) (TLE)
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int rst = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] - arr[j] == difference){
                dp[i] = max(dp[i], dp[j] + 1);
                rst = max(rst, dp[i]);
            }
        }
    }

    return rst;

}