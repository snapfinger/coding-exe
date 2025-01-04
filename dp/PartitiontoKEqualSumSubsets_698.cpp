#include "../common_headers.h"

// DP
// TC: O(n * 2^n)
bool canPartitionKSubsets(vector<int>& nums, int k) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum % k) return false;
	int target = sum / k;
	int n = nums.size();
	int dp[1 << n];
	fill(dp, dp+(1<<n), -1);
	dp[0] = 0;
	
	for(int mask=0; mask<(1<<n); mask++){
		if(dp[mask] == -1) continue;
		for(int j=0; j<n; j++){
			if(!(mask & (1<<j)) && (dp[mask] + nums[j] <= target)){
					dp[mask | (1 << j)] = (dp[mask] + nums[j]) % target;
			}
		}
		
	}
	
	return dp[(1<<n) - 1] == -1 ? false: true;
	
}