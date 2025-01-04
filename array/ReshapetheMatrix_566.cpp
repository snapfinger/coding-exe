#include "../common_headers.h"

// TC: O(mn)
// SC: O(mn)
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if(m * n != r * c) return mat;
    vector<vector<int>> mat_new = vector<vector<int>>(r, vector<int>(c, 0));
    
    for(int i = 0; i < m * n; i++){
        mat_new[i/c][i%c] = mat[i/n][i%n];
    }
    
    return mat_new;
}