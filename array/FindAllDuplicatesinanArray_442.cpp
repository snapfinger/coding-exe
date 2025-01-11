#include "../common_headers.h"

// TC: O(n)
// SC: O(1)
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> rst;
    for(int i = 0; i < nums.size(); i++){
        int idx = abs(nums[i]) - 1;
        if(nums[idx] < 0) rst.push_back(idx + 1);
        nums[idx] = -nums[idx];
    }
    return rst;
}