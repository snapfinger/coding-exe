int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> dp1(n, vector<bool>(n, false));
    vector<int> dp2(n);
    
    for(int r = 0; r < n; r++){
        dp2[r] = r;
        for(int l = 0; l <= r; l++){
            if(s[l] == s[r] && (r-l <= 2 || dp1[l+1][r-1])){
                dp1[l][r] = true;
                dp2[r] = (l == 0) ? 0: min(dp2[r], dp2[l-1]+1);
            }
        }
    }
    
    return dp2[n-1];
}