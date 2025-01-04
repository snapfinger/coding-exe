#include "../common_headers.h"

//  1D DP
int maxProduct(vector<int>& nums) {
    int rst = nums[0], cur_max = rst, cur_min = rst;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > 0){
            cur_max = max(cur_max * nums[i], nums[i]);
            cur_min = min(cur_min * nums[i], nums[i]);
        }else{
            int tmp = cur_max;
            cur_max = max(cur_min * nums[i], nums[i]);
            cur_min = min(tmp * nums[i], nums[i]);
        }
        rst = max(rst, cur_max);
    }
    return rst;
}

int main(){
    vector<int> n1 = {2, 3, -2, 4};
    maxProduct(n1);
}