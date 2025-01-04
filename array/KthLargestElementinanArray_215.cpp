#include "../common_headers.h"

// use a min heap
// TC: O(n logn)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto n: nums){
        pq.push(n);
        if(pq.size() > k) pq.pop();
    }
    
    return pq.top();
}

// use a max heap
// TC: O(n logn)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(auto n: nums) pq.push(n);
    for(int i = 0; i < k-1; i++){
        pq.pop();
    }
    
    return pq.top();
}