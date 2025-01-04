#include "../common_headers.h"

// TC: O(nlogn + M) where n is #strings, M is max size of a string
// SC: O(1)
string longestCommonPrefix(vector<string>& strs) {
    string rst = "";
    // O(nlogn) for sorting in lexical order
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int i = 0;
    while(i < first.size() && i < last.size()){
        if(first[i] != last[i]) return rst;
        rst += first[i];
        i++;
    }
    return rst;
}


// Time: O(n)
// Space: O(n)
string longestCommonPrefix1(vector<string>& strs) {
    string ans = "";
    if(!strs.size()) return ans;

    // find commond length
    int strlen = 200;
    for(int i = 0; i < strs.size(); i++){
        if(strs[i].size() < strlen){
            strlen = strs[i].size();
        }
    } 

    for(int k = 0; k < strlen; k++){
        char common = strs[0][k];
        for(int i = 1; i < strs.size(); i++){
            if(strs[i][k] != common){
                return ans;
            }
        }
        ans += common;
    }

    return ans;
}


int main(){
    vector<string> input1 = {"flower","flow","flight"};
    cout << longestCommonPrefix1(input1) << endl;

    vector<string> input2 = {"flower"};
    cout << longestCommonPrefix1(input2) << endl;
}
