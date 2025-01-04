#include "../common_headers.h"

// see also: 121. best time to buy and sell stock

int maxSubArray(vector<int>& nums) {
    int cur_max = 0, all_max = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++){
        cur_max = max(nums[i], cur_max + nums[i]);
        all_max = max(all_max, cur_max);
    }
    return all_max;
}