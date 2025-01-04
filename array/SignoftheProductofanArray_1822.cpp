
#include "../common_headers.h"

int arraySign(vector<int>& nums) {
    int neg_cnt = 0;
    for(auto n: nums){
        if(n == 0) return 0;
        else{
            if(n < 0){
                neg_cnt++;
            }
        }
    }
    return neg_cnt % 2 ? -1: 1;
}