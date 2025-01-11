#include "../common_headers.h"


// greedy
// TC: O(n)
// SC: O(1)
bool canJump(vector<int>& nums) {
    int range = 0;
    for(int i = 0; i <= range; i++){
        int cur_range = i + nums[i];
        range = max(cur_range, range);
        if(range >= nums.size() - 1) return true;
    }
    return false;
}