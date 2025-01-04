#include "../common_headers.h"

// Alternative sol (more delicate): 
// https://leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C%2B%2B-time-O(n)-space-O(n)
// Use bit operation: i & (i-1)

// My sol
// Time: O(n)
// Space: O(n)
vector<int> countBits(int n) {
    vector<int> res;
    res.push_back(0);
    
    if(n == 0){
        return res;
    }
    
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(pow(2, cnt) == i){
            res.push_back(1);
            cnt++;
        }else{
            res.push_back(1 + res[i-pow(2,cnt-1)]);    
        }
    }
    
    return res;
}