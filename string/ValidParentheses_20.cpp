// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

#include "../common_headers.h"


// a more elegent solution
bool isValid1(string s) {
        if(s.size() % 2) return false;
        stack<char> st;
        for(auto c: s){
            if(c == '[') st.push(']');
            else if(c == '(') st.push(')');
            else if(c == '{') st.push('}');
            else if(st.empty() || c != st.top()) return false;
            else st.pop();
        }
        
        return st.empty();
}


// my solution
bool isValid0(string s) {
    if(s.size() % 2) return false;
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(!st.empty() && (((s[i] == ')') && (st.top() == '(')) || 
           ((s[i] == ']') && (st.top() == '[')) ||
           ((s[i] == '}') && (st.top() == '{')))){
                st.pop();
           }else{
            st.push(s[i]);
           }
    }

     return st.empty();
}




int main(){
    string s1 = "()(";
    cout << isValid1(s1) << endl;

    string s2 = "[]";
    cout << isValid1(s2) << endl;

    string s3 = "(){}}{";
    cout << isValid1(s3) << endl;


    return 1;
}