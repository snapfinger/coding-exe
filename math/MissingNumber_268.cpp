#include "../common_headers.h"


// TC: O(n)
int missingNumber(vector<int>& nums) {
    int intended_sum = (1 + nums.size()) * nums.size() / 2.0;
    int actual = accumulate(nums.begin(), nums.end(), 0);
    return (int)(intended_sum - actual);
}