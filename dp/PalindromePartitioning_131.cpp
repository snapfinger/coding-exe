#include "../common_headers.h"


// DP + backtracking
// TC:
// DP part: O(n^2)
// backtracking part: 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int r = 0; r < n; r++){
            dp[r][r] = true;
            for(int l = 0; l < r; l++){
                if((s[l] == s[r]) && ((r - l == 1) || dp[l+1][r-1])){
                    dp[l][r] = true;
                }
            }
        }

        vector<vector<string>> rst;
        vector<string> cur_rst;

        helper(dp, s, 0, rst, cur_rst);

        return rst;

    }

    void helper(vector<vector<bool>>& dp, string s, int start_idx, vector<vector<string>>& rst, vector<string>& cur_rst){
        if(start_idx == s.size()){
            rst.push_back(cur_rst);
            return;
        }

        for(int i = start_idx; i < s.size(); i++){
            if(dp[start_idx][i] == false) continue;
            else{
                cur_rst.push_back(s.substr(start_idx, i - start_idx + 1));
                helper(dp, s, i+1, rst, cur_rst);
                cur_rst.pop_back();
            }
        }
    }
};