
// Sol 2: hashset
int longestPalindrome(string s) {
    int count = 0;
    unordered_set<char> set;
    for(auto c: s){
        if(set.count(c)){
            set.erase(c);
            count++;
        }else{
            set.insert(c);
        }
    }
    
    return set.empty()? count * 2: count * 2 + 1;
}

// Sol 1: hashmap
// TC: O(n)
// SC: O(26)
int longestPalindrome(string s) {
    int rst = 0;
    bool mid = false;
    unordered_map<char, int> m;
    for(auto c: s){
        m[c] += 1;
    }
    
    for(auto p: m){
        rst += p.second;
        if(p.second % 2){
            rst -= 1;
            mid = true;
        }
        
    }
    
    return mid ? rst + 1: rst;
    
}