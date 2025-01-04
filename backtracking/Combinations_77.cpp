#include "../common_headers.h"


// TC: O(C(n, k) * k)
// SC: O(k)
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> rst;
    vector<int> cur;
    helper(rst, cur, 1, n, k);
    return rst;
}

void helper(vector<vector<int>>& rst, vector<int>& cur, int start, int n, int k){
    if(cur.size() == k){
        rst.push_back(cur);
    }
    
    for(int i = start; i <= n; i++){
        cur.push_back(i);
        helper(rst, cur, i+1, n, k);
        cur.pop_back();
    }
}