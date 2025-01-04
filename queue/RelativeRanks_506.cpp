#include "../common_headers.h"

// TC: O(n logn)
vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> rst(score.size(), "");
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < score.size(); i++){
        q.push(make_pair(score[i], i));
    }
    
    for(int i = 0; i < score.size(); i++){
        pair<int, int> cur = q.top();
        q.pop();
        if(i == 0) rst[cur.second] = "Gold Medal";
        else if(i == 1) rst[cur.second] = "Silver Medal";
        else if(i == 2) rst[cur.second] = "Bronze Medal";
        else{
            rst[cur.second] = to_string(i + 1);
        }
    }
    
    return rst;
    
}