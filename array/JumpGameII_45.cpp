// Sol 2: greedy
// O(n)
// O(1)
int jump(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0, right = 0, reach = 0;
    
    for(int i = 0; i < n - 1; i++){
        reach = max(reach, i + nums[i]);
        if(i == right){
            right = reach;
            cnt++;
        }
    }
    
    return cnt;
        
}


// Sol 1: my sol
// TC: O(n^2) (worst case, every element = n)
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    
    int cnt = 0;
    dp[0] = 0;
    
    for(int i = 0; i < n; i++){
        int reach = i + nums[i];
        cnt = dp[i] + 1;
        for(int j = i+1; j < n && j <= reach; j++){
            dp[j] = min(dp[j], cnt);
            if(dp[n-1] < INT_MAX) return dp[n-1];
        }
    }
    
    return dp[n-1];
    
}