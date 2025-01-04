#include "../common_headers.h"


// TC: O(n)
// Auxiliary space: O(1)
vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<vector<int>> rst;
    
    if(nums.empty()) return {{lower, upper}};
    
    if(lower < nums[0]) rst.push_back({lower, nums[0]-1});
    
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] > 1){
            rst.push_back({nums[i-1]+1, nums[i]-1});
        }
    }
    
    if(upper > nums.back()) rst.push_back({nums.back()+1, upper});
    
    return rst;
}