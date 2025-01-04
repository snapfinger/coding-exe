#include "../common_headers.h"

// hashmap
// TC: O(n)
// SC: O(n)
int subarraySum(vector<int>& nums, int k) {
    int sum = 0, cnt = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        cnt += m[sum - k];
        m[sum]++;
    }
    
    return cnt;
}