// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// Solution 2: hashmap
// Time: O(n)
// Space: O(n) 
vector<int> twoSum2(vector<int>& nums, int target) {
    unordered_map<int, int> rec;
    for(int i=0; i<nums.size(); i++){
        if(rec.find(nums[i]) != rec.end()){
            return {i, rec[nums[i]]};
        }else{
            rec.insert(make_pair(target - nums[i], i));
        }
    }
    return vector<int>{};
}


// Solution 1: brute force
// Time: O(n^2)
// Space: O(1) 
vector<int> twoSum1(vector<int>& nums, int target) {
    for(int i=0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                vector<int> rst = {i, j};
                return rst;
            }
        }
    }
    return vector<int>{};
}

int main(){
    vector<int> input1 = {1, 2, 3, 4};
    int t1 = 3;
    vector<int> res = twoSum2(input1, t1);
    for (auto v: res){
        cout << v << ' ';
    }
    cout << endl;
}


