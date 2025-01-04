// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105

#include "../common_headers.h"


// Solution 1: hashmap 
// Time: O(n)
// Space: O(n)
bool containsNearbyDuplicate1(vector<int>& nums, int k){
    if(!nums.size()) return false;
    unordered_map<int, int> rec;
    
    for(int i = 0; i < nums.size(); i++){
        if((rec.find(nums[i]) != rec.end()) && (abs(i - rec[nums[i]]) <= k)){
            return true;
        }else{
            rec[nums[i]] = i;
        }
    }
        
    return false;
    
}


int main(){
    vector<int> input1 = {1, 2, 3, 1, 2, 3};
    cout << "res: " << containsNearbyDuplicate1(input1, 2) << endl; 
}