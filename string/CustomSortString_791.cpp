#include "../common_headers.h"


// TC: O(nlogn + klogk)
// n: size of "order"
// k: size of  "s"
// SC: O(n) + O(log k)
string customSortString(string order, string s) {
    map<char, int> m;
    for(int i = 0; i < order.size(); i++){
        m[order[i]] = i + 1;
    }
    
    sort(s.begin(), s.end(), [&](char a, char b){return m[a] < m[b];});
    
    return s;
}