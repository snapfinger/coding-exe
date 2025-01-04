#include "../common_headers.h"

 bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

int main(){
    string s1 = "leetcode";
    vector<string> v1 = {"leet", "code"};
    cout << wordBreak(s1, v1) << endl;
}