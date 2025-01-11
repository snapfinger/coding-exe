#include "../common_headers.h"

// Assume sorted by the first element, left side <= right side
// [[2, 5], [2, 3], [4, 6]] => [224, 225, 226, 234, 235, 236, ...]

void helper(vector<vector<int>>& input, vector<int>& rst, int i, int cur){
    if(i == input.size()){
        rst.push_back(cur);
        return;
    }

    for(int val = input[i][0]; val <= input[i][1]; val++){
        cur = cur * 10 + val;
        helper(input, rst, i + 1, cur);
        cur = (cur - val) / 10;
    }
}

vector<int> get_comb(vector<vector<int>>& input){
    vector<int> rst;
    helper(input, rst, 0, 0);
    return rst;
}


int main(){
    vector<vector<int>> input = {{2, 5}, {2, 3}, {4, 6}};
    auto rst = get_comb(input);
    for(auto v: rst){
        cout << v << " ";
    }
    cout << endl;
}
