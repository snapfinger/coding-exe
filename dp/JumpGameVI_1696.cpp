#include "../common_headers.h"

// TC: O(n)
// SC: O(k)
int maxResult(vector<int>& nums, int k) {
    deque<int> dp{0};
    for(int i = 1; i < nums.size(); i++){
        if(i - dp.front() > k) dp.pop_front();
        nums[i] = nums[dp.front()] + nums[i];
        while(!dp.empty() && nums[dp.back()] <= nums[i]) dp.pop_back();
        dp.push_back(i);
        
    }
    return nums[nums.size() - 1];
}