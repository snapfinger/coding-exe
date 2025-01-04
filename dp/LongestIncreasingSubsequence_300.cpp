#include "../common_headers.h"

// Sol 1:
// DP + binary search
// TC: O(n logn)
// SC: O(n)
int lengthOfLIS1(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;
    for(int i = 0; i < n; i++){
        int cur = nums[i], left = 0, right = dp.size();

        while(left < right){
            int mid = left + (right - left) / 2;
            if(dp[mid] < cur) left = mid + 1;
            else right = mid;
        }

        if(right == dp.size()) dp.push_back(cur);
        else dp[right] = cur;

    }

    return dp.size();
}


// Sol 2:
// 1D DP
// TC: O(n^2)
// SC: O(n)
int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int rst = 0;
    for(auto d: dp) rst = max(d, rst);
    return rst;
}