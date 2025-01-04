#include "../common_headers.h"

// TC: O(n) (n: #elements of nums)
// SC: O(k)
int subarraysDivByK(vector<int>& nums, int k) {
    int sum = 0, cnt = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;
    for(auto n: nums){
        sum += n;
        int rem = sum % k;
        if(rem < 0) rem += k;
        // cout << "n: " << n << " | rem: " << rem << endl;
        cnt += freq[rem];
        freq[rem]++;
    }
        
    return cnt;
}