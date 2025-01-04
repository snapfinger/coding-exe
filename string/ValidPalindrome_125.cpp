// TC: O(n)
// SC: O(1)
bool isPalindrome2(string s) {
    int i = 0, j = s.size() - 1; 
    while(i < j){
        while (!isalnum(s[i]) && i < j) i++; 
        while (!isalnum(s[j]) && i < j) j--; 
        if (toupper(s[i]) != toupper(s[j])) return false;
        i++; j--;
    }

return true;
}

// TC: O(n) n: length of the input
// SC: O(n) 
bool isPalindrome(string s) {
    string str;
    for(auto c: s){
        if(isalnum(c)){
            str.push_back(tolower(c));
        }
    }
    
    int i = 0, j = str.size() - 1;
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}