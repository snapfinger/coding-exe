#include "../common_headers.h"


// TC:
// there are C_k^9 combinations
// each combination needs O(k) time to track
// => O(k * C_k^9)

// SC: 
// auxiliary space: O(k) (recursion stack depth can go at most k)
// space for output: O(k * C_k^9)
// => O(k * C_k^9)
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> rst;
    vector<int> cur;
    helper(rst, cur, 0, k, n, 1);
    return rst;
}

void helper(vector<vector<int>>& rst, vector<int>& cur, int sum, int k, int n, int start){
    if((cur.size() == k) && (sum == n)){
        rst.push_back(cur);
        return;
    }else if(cur.size() > k){
        return;
    }
    
    for(int i = start; i <= 9; i++){
        sum += i;
        cur.push_back(i);
        helper(rst, cur, sum, k, n, i+1);
        sum -= i;
        cur.pop_back();
    }
}