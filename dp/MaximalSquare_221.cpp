#include "../common_headers.h"

// TC: O(mn)
// SC: O(mn)
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int max_all = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == '1'){ 
                if(i == 0 || j == 0) dp[i][j] = 1;
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    max_all = max(max_all, dp[i][j]);
            }
        }
    }
    return pow(max_all, 2);
}