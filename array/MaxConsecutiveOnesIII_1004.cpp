#include "../common_headers.h"

int longestOnes(vector<int>& nums, int k) {
    int left = 0, rst = 0, num_zero = 0;
    for(int right = 0; right < nums.size(); right++){
        if(nums[right] == 0) num_zero++;
        if(num_zero > k){
            if(nums[left] == 0) num_zero--;
            left++;
        }
        
        rst = max(rst, right - left + 1);
    }
    return rst;
}