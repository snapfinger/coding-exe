#include "../common_headers.h"


// method 2: bfs
// replace queue with stack to get dfs iterative sol
// TC: O(V + E)
// SC: O(V + E)
bool validTree2(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> visited(n, false);
    queue<pair<int, int>> q;

    for(auto e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    q.push({0, -1});
    while(!q.empty()){
        auto tmp = q.front(); q.pop();
        auto cur = tmp.first, pre = tmp.second;
        visited[cur] = true;

        for(auto nb: adj[cur]){
            if(nb != pre) {
                if(visited[nb]) return false;
                q.push({nb, cur});
            }
        }
    }

    for(auto v: visited){
        if(!v) return false;
    }

    return true;
}

// method 1: dfs recursive
// TC: O(V + E)
// SC: O(V)
bool validTree1(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> visited(n, false);

    for(auto e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    if(!dfs(adj, visited, -1, 0)) return false;

    for(auto v: visited){
        if(!v) return false;
    }

    return true;
}

bool dfs(vector<vector<int>>& adj, vector<int>& visited, int pre, int cur){
    if(visited[cur]) return false;
    visited[cur] = true;

    for(auto nb: adj[cur]){
        if(nb != pre) {
            if(!dfs(adj, visited, cur, nb)) return false;
        }
    }

    return true;

}