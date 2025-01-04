#include "../common_headers.h"

void print2D(vector<vector<int> >& mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Same as knapsack problem
int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
    int len = present.size();
//  dp[i][j]: largest profit among 0 - i stocks, with budget j
    vector<vector<int>> dp(len + 1, vector<int>(budget + 1, 0));

    for(int j=0; j<=budget; j++){ 
        for(int i=0; i<present.size(); i++){

            cout << "i: " << i << " j: " << j << endl; 
            if(j < present[i]){
                dp[i + 1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-present[i]] + future[i] - present[i]);
            }

            print2D(dp);
        }
    }
    
    return dp[len][budget];
}



int main(){
    // vector<int> p1 = {2, 2, 5};
    // vector<int> f1 = {3, 4, 10};
    // int b1 = 4;
    // cout << maximumProfit(p1, f1, b1) << endl;
    vector<vector<int>> tmp = {{1, 3}, {2, 4}};
    cout << tmp.back()[0] << " " << tmp.back()[1] << endl;
}