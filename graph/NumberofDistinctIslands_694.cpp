#include "../common_headers.h"


class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> s;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfsHelper(grid, i, j, i, j, vec);
                    s.insert(vec);
                }
            }
        }
        
        return s.size();
    }
    
    void dfsHelper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<pair<int, int>>& vec){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return;
        grid[i][j] = 0;
        vec.push_back({i - x0, j - y0});
        
        for(auto dir: dirs){
            dfsHelper(grid, x0, y0, i+dir[0], j+dir[1], vec);
        }
    }
};