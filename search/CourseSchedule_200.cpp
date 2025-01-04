#include "../common_headers.h"
w
// TC: O(E + V)
// where V: #courses, E: #jdependencies
// SC: O(E + V)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>());
    vector<int> in(numCourses, 0);
    for(auto &pre: prerequisites){
        adj[pre[1]].push_back(pre[0]);
        in[pre[0]]++;
    }
    queue<int> q;
    for(int i=0; i<in.size(); i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nb: adj[node]){
            in[nb]--;
            if(in[nb] == 0) q.push(nb);
        }
    }
    
    for(auto i: in){
        if(i) return false;
    }
    return true;
}


int main(){
    int n1 = 2;
    vector<pair<int, int>> pre1 = {{1, 0}, {0, 1}};
    cout << canFinish(n1, pre1) << endl;
}

