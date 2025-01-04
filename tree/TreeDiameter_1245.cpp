#include "common_headers.h"

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int diameter = 0;
        vector<vector<int>> adj(edges.size() + 1);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(adj.size(), false);
        dfsHelper(adj, visited, 0, diameter);
        
        return diameter;
        
    }
        
    int dfsHelper(vector<vector<int>>& adj, vector<bool>& visited, int i, int& diameter){
        int max_depth = 0;
        visited[i] = true;
        
        for(auto nb: adj[i]){
            if(!visited[nb]){
                int depth = dfsHelper(adj, visited, nb, diameter);
                diameter = max(diameter, depth + max_depth);
                max_depth = max(depth, max_depth);
            }
        }
        
        return i == 0? diameter : max_depth + 1;

    }
        
};