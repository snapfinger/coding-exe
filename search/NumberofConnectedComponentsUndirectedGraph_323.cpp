#include "../common_headers.h"

// TC: O(n)
// SC: O(n)
int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int rst = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            rst += 1;
            dfs(adj, vis, i);
        }
    }

    return rst;
}

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int i){
    if(vis[i]) return;

    vis[i] = true;

    for(int j = 0; j < adj[i].size(); j++){
        dfs(adj, vis, adj[i][j]);
    }
}