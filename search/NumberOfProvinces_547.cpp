#include "../common_headers.h"


// TODO: Sol 2: Union-find


// Solution 1: DFS recursive
// TC: O(n^2)
// SC: O(n)
int findCircleNum(vector<vector<int>>& isConnected) {
    int count = 0;
    
    vector<bool> visited(isConnected.size(), false);
    
    for(int i = 0; i < isConnected.size(); i++){
        if(visited[i] == false){
            count++;
            dfsHelper(isConnected, visited, i);
        }
    }
    return count;
}

void dfsHelper(vector<vector<int>>& mat, vector<bool>& visited, int i){
    
    visited[i] = true;
    
    for(int j = 0; j < visited.size(); j++){
        if(!visited[j] && mat[i][j] && (i!=j)){
            dfsHelper(mat, visited, j);
        }
    }
    
    return;
}