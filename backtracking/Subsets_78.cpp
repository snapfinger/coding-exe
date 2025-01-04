vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> rst;
    vector<int> cur;
    helper(rst, cur, nums, 0);
    return rst;
}

void helper(vector<vector<int>>& rst, vector<int>& cur, vector<int>& nums, int start){
    rst.push_back(cur);
    
    for(int i = start; i < nums.size(); i++){
        cur.push_back(nums[i]);
        helper(rst, cur, nums, i+1);
        cur.pop_back();
    } 
}