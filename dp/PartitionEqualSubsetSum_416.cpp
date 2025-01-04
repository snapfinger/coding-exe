#include "../common_headers.h"

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2) return false;
    
    int target = sum / 2;
    int n = nums.size();
    
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
            
    for(int i=0; i<n; i++){
        for(int j=1; j<=target; j++){
            dp[i+1][j] = dp[i][j];
            if(j >= nums[i]){
                dp[i+1][j] = dp[i][j] | dp[i][j - nums[i]];
            }
        }
    }
    
    return dp[n][target];
    
}

int main(){
    vector<int> n1 = {1, 5, 11, 5};
    cout << canPartition(n1) << endl;
}