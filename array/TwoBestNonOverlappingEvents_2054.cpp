#include "../common_headers.h"

// See also: 
// TC: O(n logn)
// SC: O(n)
int maxTwoEvents(vector<vector<int>>& events) {
    vector<vector<int>> recs;
    for(auto e: events){
        int start = e[0];
        int end = e[1];
        int val = e[2];
        recs.push_back({start, 1, val});
        recs.push_back({end + 1, 0, val});
    }

    sort(recs.begin(), recs.end());

    int rst = 0, max_finished = 0;

    for(auto rec: recs){
        int start = rec[0];
        int is_start = rec[1];
        int val = rec[2];

        if(is_start){
            rst = max(rst, val + max_finished);
        }else{
            max_finished = max(max_finished, val);
        }
    }

    return rst;
}