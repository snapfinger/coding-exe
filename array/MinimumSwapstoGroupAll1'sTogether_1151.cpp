#include "../common_headers.h"


// Two pointers
// TC: O(n)
// SC: O(1)
int minSwaps(vector<int>& data) {
    int cnt_ones = 0;
    for(auto d: data){
        cnt_ones += d;
    }
    
    int max_cur = 0, max_all = 0;
    int left = 0, right = 0;
    while(right < data.size()){
        max_cur += data[right++];
        if(right - left > cnt_ones){
            max_cur -= data[left++];
        }
        max_all = max(max_all, max_cur);
    }
    
    return cnt_ones - max_all;
    
    
}