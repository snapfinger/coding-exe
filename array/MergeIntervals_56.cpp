#include "../common_headers.h"

// TC: O(n logn)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> rst;
    sort(intervals.begin(), intervals.end());
    
    for(auto interval: intervals){
        if(rst.empty() || interval[0] > rst.back()[1]){
            rst.push_back(interval);
        }else{
            rst.back()[1] = max(rst.back()[1], interval[1]);
        }
    }
    return rst;
}