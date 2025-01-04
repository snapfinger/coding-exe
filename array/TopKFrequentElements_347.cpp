#include "../common_headers.h"

// bucket sort
// TC: O(n)
// SC: O(n)
vector<int> topKFrequent(vector<int>& nums, int k){
    vector<int> rst;
    unordered_map<int, int> map;
    vector<vector<int>> bucket(nums.size() + 1);
    for(auto n: nums){
        map[n]++;
    }
    
    for(auto entry: map){
        auto freq = entry.second, val = entry.first;
        bucket[freq].push_back(val);
    }
    
    for(int j = nums.size(); j > 0; j--){
        for(int i = 0; i < bucket[j].size(); i++){
            if(rst.size() == k) return rst;
            rst.push_back(bucket[j][i]);
        }
    }
    
    return rst;
}


// min heap
// TC: (O(nlogk)
// SC: O(n)
struct CompareFirst {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first; // For a min heap
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    vector<int> rst;
    for(auto n: nums){
        map[n]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareFirst> pq;
    for(auto n: map){
        auto val = n.first, freq = n.second;
        if(pq.size() < k) pq.push({freq, val});
        else if(freq > pq.top().first){
            pq.pop();
            pq.push({freq, val});
        }
    }
    
    while(!pq.empty()){
        auto val = pq.top().second;
        rst.push_back(val);
        pq.pop();
    }
    
    return rst;
}