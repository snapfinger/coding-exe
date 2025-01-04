#include "../common_headers.h"

// Sol1: recursion
// TC: average O(nlogn), worst O(n^2) (when its monotonic vector)
// SC: average O(logn), worse O(n)
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if(nums.empty()) return nullptr;
    return helper(nums, 0, nums.size()-1);
}

TreeNode* helper(vector<int>& nums, int left, int right){
    if(left > right) return nullptr;
    
    int mid = left;
    for(int i = left; i <= right; i++){
        if(nums[i] > nums[mid]) mid = i;
    }
    
    TreeNode* cur_root = new TreeNode(nums[mid]);
    cur_root->left = helper(nums, left, mid-1);
    cur_root->right = helper(nums, mid+1, right);
    return cur_root;
}