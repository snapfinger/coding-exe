#include "../common_headers.h"

// (N: #words in words, S: length of the order string)
// TC: O(NS)
// SC: O(1)
bool isAlienSorted(vector<string>& words, string order) {
    vector<int> m(26, 0);
    for(int i = 0; i < 26; i++){
        m[order[i] - 'a'] = i;
    }
    
    for(string& s: words){
        for(char& c: s){
            c = m[c - 'a']; 
        }
    }
    
    return is_sorted(words.begin(), words.end());
}


// TC: O(N^2 + M) (N: #words in words, M: length of the order string)
bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> m;
    for(int i = 0; i < order.size(); i++){
        m[order[i]] = i;
    }
    
    for(int i = 0; i < words.size(); i++){
        for(int j = i + 1; j < words.size(); j++){
            int c = 0;
            
            while(c < words[i].size()){
                if(c == words[j].size()) return false;
                int pos1 = m[words[i][c]], pos2 = m[words[j][c]];
                
                if(pos1 < pos2) break;
                
                if(pos1 == pos2){
                    c++;
                    continue;
                }
                
                if(pos1 > pos2) return false;
            }
            
        }
    }
    
    return true;
}