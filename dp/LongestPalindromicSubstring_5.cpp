#include "../common_headers.h"

// 2D DP
// TC: O(n^2)
// SC: O(n^2)
string longestPalindrome(string s) {
    int start_idx = 0, max_len = 1;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for(int r = 0; r < s.size(); r++){
        dp[r][r] = true;
        for(int l = r - 1; l >= 0; l--){
            if((s[l] == s[r]) && ((r - l == 1) || dp[l+1][r-1])){
                dp[l][r] = true;
                if(r - l + 1 > max_len){
                    max_len = r - l + 1;
                    start_idx = l;
                }
            }
        }
    }

    return s.substr(start_idx, max_len);
}