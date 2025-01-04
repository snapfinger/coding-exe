vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> rst;
    vector<int> cur;
    helper(rst, cur, candidates, 0, target, 0);
    return rst;
}

void helper(vector<vector<int>>& rst, vector<int>& cur, vector<int>& candidates, int start, int target, int sum){
    if(sum == target){
        rst.push_back(cur);
    }else if(sum > target){
        return;
    }
    
    for(int i = start; i < candidates.size(); i++){
        sum += candidates[i];
        cur.push_back(candidates[i]);
        helper(rst, cur, candidates, i, target, sum);
        cur.pop_back();
        sum -= candidates[i];
    }
}