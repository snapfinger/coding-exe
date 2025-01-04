#include "../common_headers.h"

class KthLargest {
    int size_;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
// TC: O(nlogk)
// n: #elements in nums
// SC: O(k)
    KthLargest(int k, vector<int>& nums) {
        size_ = k;
        for(auto n: nums){
            pq.push(n);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    // TC: O(log n)
    int add(int val) {
        pq.push(val);
        if(pq.size() > size_) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */