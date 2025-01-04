#include "../common_headers.h"
    

// TC: O(n log(weights_sum))
// n: length of weights
// SC: O(1)
int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for(auto w: weights){
            left = max(w, left);
            right += w;
        }
        
        while(left < right){
            int mid = left + (right - left) / 2, cur_sum = 0, cur_days = 1;
            for(auto w: weights){
                cur_sum += w;
                if(cur_sum > mid){
                    cur_days += 1;
                    cur_sum = w;
                }
            }
            
            if(cur_days > days){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        
        return right;
    }