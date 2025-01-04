// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]
 
// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.


// bit masking
// TC: O(n * 2^n)
// SC: O(n * 2^n)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> rst = {};
    int n = nums.size();
    
    for(int mask=0; mask < (1<<n); mask++){
        vector<int> cur_rst = {};
        for(int i=0; i<nums.size(); i++){
            if(mask & (1<<i)){
                cur_rst.push_back(nums[i]);
            }
        }
        
        rst.push_back(cur_rst);
    }
    
    return rst;
}