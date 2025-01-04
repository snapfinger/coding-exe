#include "../common_headers.h"

// TC: O(n)
string frequencySort(string s) {
    string rst = "";
    unordered_map<char, int> m1;
    for(auto c: s){
        m1[c]++;
    }
    
    map<int, string> m2;
    for(auto p: m1){
        char c = p.first;
        int freq = p.second;
        m2[freq] += string(freq, c);
    }
    
    for(auto p=m2.rbegin(); p!=m2.rend(); p++){
        rst += p->second;
    }
    
    return rst;
}