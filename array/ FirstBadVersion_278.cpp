#include "../common_headers.h"

bool isBadVersion(int val){
    // provided as an API
}


// O(log n)
int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) right = mid;
        else left = mid + 1;
    }
    return right;
}