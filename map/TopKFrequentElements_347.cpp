#include "../common_headers.h"

// TC: max{O(n), O(D logD + k)} where D is #unique elements
// under worst case situation, D = n, and TC = O(nlogn)
// SC: O(D)
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> rst;
    unordered_map<int, int> m1;
    for(auto n: nums){
        m1[n]++;
    }
    
    map<int, vector<int>> m2;
    for(auto p: m1){
        int num = p.first;
        int freq = p.second;
        m2[freq].push_back(num);
    }
    
    int cnt = 0;
    for(auto p = m2.rbegin(); p != m2.rend(); p++){
        for(auto n: p->second){
            rst.push_back(n);
            cnt++;
            if(cnt == k) return rst;
        }
    }
    
    return rst;
    
}