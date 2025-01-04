// include "../common_headers.h"

// with a 26-size vector
// TC: O(n)
// SC: O(1)
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for(int i = 0; i < s.size(); i++){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    for(auto a: count){
        if(a) return false;
    }
    
    return true;
}

// my solution
bool isAnagram(string s, string t) {
    map<char, int> m1;
    map<char, int> m2;
    for(auto c: s){
        m1[c]++;
    }
    
    for(auto c: t){
        m2[c]++;
    }
    
    if(m1.size() != m2.size()) return false;
        
    for(auto i1=m1.begin(), i2=m2.begin(); i1 != m1.end() && i2!= m2.end(); i1++, i2++){
        if(i1->first != i2->first || i1->second != i2->second) return false;
    }
    
    return true;
    
}
