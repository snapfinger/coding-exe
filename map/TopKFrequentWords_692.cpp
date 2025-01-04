#include "../common_headers.h"

// Sol 2: TODO: 
// TC: O(nlogk)

// Sol 1: unordered_map + map
// TC: O(nlogn)
vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> rst;
    unordered_map<string, int> m1;
    for(auto word: words){
        m1[word]++;
    }
    
    map<int, vector<string>> m2;
    for(auto p: m1){
        m2[p.second].push_back(p.first); 
    }
    
    for(auto p: m1){
        sort(m2[p.second].begin(), m2[p.second].end()); 
    }
    
    int cnt = 0;
    for(auto iter = m2.rbegin(); iter != m2.rend(); iter++){
        for(auto str: iter -> second){
            rst.push_back(str);
            cnt++;
            if(cnt == k) return rst;
        }
    }
    
    return rst;
}