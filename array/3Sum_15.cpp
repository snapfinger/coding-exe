#include "../common_headers.h"
    
// two pointers 
// TC: O(n^2)
// SC: O(n) to O(log n) depending on the sorting algo
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> rst;
    sort(begin(nums), end(nums));
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) continue;
        if(i == 0 || nums[i] != nums[i-1]){
            helper(i, nums, rst);
        }
    }
    
    return rst;
}

void helper(int i, vector<int>& nums, vector<vector<int>>& rst){
    int low = i + 1, high = nums.size() - 1;
    while(low < high){
        int sum = nums[i] + nums[low] + nums[high];
        if(sum < 0) low += 1;
        else if(sum > 0) high -= 1;
        else{
            rst.push_back({nums[i], nums[low++], nums[high--]});
            while((low < high) && (nums[low] == nums[low-1])) low += 1;
        }
    }
}


// hashmap + unordered_set + set
// TC: O(n^2)
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> rst;
    unordered_set<int> dups;
    unordered_map<int, int> seen;
    
    for(int i = 0; i < nums.size(); i++){
        if(dups.count(nums[i])) continue;
        else{
            dups.insert(nums[i]);
            for(int j = i + 1; j < nums.size(); j++){
                int comp = -nums[i] - nums[j];
                if(seen.count(comp) && seen[comp] == i){
                    vector<int> cur = {nums[i], nums[j], comp};
                    sort(begin(cur), end(cur));
                    rst.insert(cur);
                }
                seen[nums[j]] = i;
            }
        }
    }
    
    return vector<vector<int>>(begin(rst), end(rst));
    
}