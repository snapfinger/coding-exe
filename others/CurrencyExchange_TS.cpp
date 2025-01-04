#include "../common_headers.h"

float findMax(vector<vector<float>> table, int src, int dst){
    int n = table.size();
 
    vector<vector<float>> dp(1<<n, vector<float>(n, INT_MIN));

    // init: src 
    // taken log, product => sum
    dp[1 << src][0] = 0;

    // step
    for(int j=1; j<n; j++){
        for(int mask = 0; mask < (1<<n); mask++){
            // iterate all currency indices
            for(int k=0; k<n; k++){
                if(dp[mask & (1<<k)][j-1] == INT_MIN) continue;
                if(mask & (1<<k)) continue;
                dp[mask | (1 << k)][j] = max(dp[mask | (1 << k)][j], dp[mask][j] + log(table[k-1][k]));
            }

        }
    }

    print2D(dp);
    // return max(dp[1<<n - 1][n-1];
    return 1;
}


int main(){
    vector<vector<float>> table = {{1, 1.3, 1, 6.49}, 
                                   {0.72, 1, 0.9, 5.5}, 
                                   {1.1, 1.1, 1, 7.3}, 
                                   {0.18, 0.2, 0.136, 1}};

    findMax(table, 0, 3);

    // cout << log(2.72) << endl;
}
