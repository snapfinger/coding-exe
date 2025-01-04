#include "../common_headers.h"

class SparseVector {
    unordered_map<int, int> m;
public:
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) m[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;g
        for(auto &ind: m){
            if(vec.m.find(ind.first) != vec.m.end()){
                sum += m[ind.first] * vec.m[ind.first];
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);