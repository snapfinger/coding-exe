// Two sigma:

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// 返回一串数字，代表相同大小的岛屿的数量值
// 用Hashmap做
 
// Example 1:

// Input: grid = [
//   ["1","1","0","1","0"],
//   ["1","1","0","1","0"],
//   ["0","0","0","0","1"],
//   ["0","0","0","0","1"]
// ]
// Output: [1, 2]



#include "../common_headers.h"


class Solution {
public:

    vector<int> numIslandsTS(vector<vector<char>>& grid) {

        vector<int> rst;
        unordered_map<int, int> map;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    int count = 0;
                    dfsHelper(grid, count, i, j);
                    map[count]++;
                }
            }
        }

        for(auto v: map){
            rst.push_back(v.second);
        }

        return rst;
    }

    void dfsHelper(vector<vector<char>>& grid, int& count, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1'){
            return;
        }

        grid[i][j] = '0';
        count++;

        dfsHelper(grid, count, i+1, j);
        dfsHelper(grid, count, i-1, j);
        dfsHelper(grid, count, i, j+1);
        dfsHelper(grid, count, i, j-1);
    
    }
};


int main(){
    Solution s1;
    vector<vector<char>> g1 = {{'1', '1', '0', '1'}, {'1', '1', '0', '1'}, {'0', '0', '0', '0'}, {'1', '1', '0', '1'}};
    // for(int i = 0; i < g1.size(); i++){
    //     for(int j = 0; j < g1[0].size(); j++){
    //         cout << g1[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    vector<int> v1 = s1.numIslandsTS(g1);
    for(auto e: v1){
        cout << e << " ";
    }
}