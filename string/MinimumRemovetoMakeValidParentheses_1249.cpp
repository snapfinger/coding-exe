#include "../common_headers.h"

// TC: O(n)
// SC: O(1)
string minRemoveToMakeValid(string s) {
        string rst;
        int left = 0, right = 0;
        for(auto c: s){
            if(c == ')') right += 1;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(left == right) continue;
                left += 1;
            }else if(s[i] == ')'){
                right -= 1;
                if(left == 0) continue;
                left -= 1;
            }
            rst += s[i];
        }
        return rst;
    }

// TC: O(n)
// SC: O(n)
string minRemoveToMakeValid(string s) {
    string rst;
    stack<int> st;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') st.push(i);
        if(s[i] == ')'){
            if(st.empty()) s[i] = '*';
            else st.pop();
        }
    }
    
    while(!st.empty()){
        s[st.top()] = '*';
        st.pop();
    }
    
    for(auto c: s){
        if(c != '*') rst += c;
    }
    
    return rst;
}