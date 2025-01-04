 #include "../common_headers.h"
 
 int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for(int i=2; i<=n; i++){
            int prev1 = s[i-1] -'0';
            int prev2 = stoi(s.substr(i-2, 2));
            if(prev1 >= 1 && prev1 <= 9) dp[i] += dp[i-1];
            if(prev2 >= 10 && prev2 <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }