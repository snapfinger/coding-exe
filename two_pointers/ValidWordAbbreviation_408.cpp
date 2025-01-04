#include "../common_headers.h"


// TC: O(n)
// SC: O(1)
bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0;
    while(i < word.size() && j < abbr.size()){
        if(isdigit(abbr[j])){
            if(abbr[j] == '0') return false;
            int sum = 0;
            while(isdigit(abbr[j])){
                sum = sum * 10 + abbr[j++] - '0';
            }
            
            i = i + sum;
        }else{
            if(word[i++] != abbr[j++]) return false;
        }
    }
    
    return (i == word.size()) && (j == abbr.size());
}