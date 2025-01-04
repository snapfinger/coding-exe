#include "../common_headers.h"


// 1D DP
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<int> dp(n, 1);
    for(int r = 0; r < n; r++){
        int prev_len = 0;
        for(int l = r-1; l >= 0; l--){
            int tmp = dp[l];
            if(s[l] == s[r]) dp[l] = prev_len + 2;
            prev_len = max(tmp, prev_len);
        }
    }

    int rst = 0;
    for(auto d: dp) rst = max(d, rst);
    return rst;
}

// 2D DP
int longestPalindromeSubseq2(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int l = n-1; l >= 0; l--){
        dp[l][l] = 1;
        for(int r = l+1; r < n; r++){
            if(s[l] == s[r]) dp[l][r] = dp[l+1][r-1] + 2;
            else{
                dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }
    }

    return dp[0][n-1];
}