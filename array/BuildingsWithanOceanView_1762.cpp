#include "../common_headers.h"

vector<int> findBuildings(vector<int>& heights) {
    vector<int> rst;
    for(int i = heights.size() - 1; i >= 0; i--){
        if(rst.empty() || heights[i] > heights[rst.back()]) rst.push_back(i);
    }
    
    return vector<int>(rbegin(rst), rend(rst));
}