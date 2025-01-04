#include "../common_headers.h"

// Note the binary search update mid point step!
// TC: O(log x)
int mySqrt(int x) {
    if(x <= 1) return x;
    int left = 1, right = x;
    while(right > left + 1){
        int mid = left + (right - left) / 2;
        if(mid > x / mid){
            right = mid;
        }else if(mid < x / mid){
            left = mid;    
        }else{
            return mid;   
        }
    }
    return left;
}