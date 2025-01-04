#include "../common_headers.h"

int countLetters(string s) {
    int rst = 0;

    char cur = s[0];
    int i = 0;
    
    while(i < s.size()){
        int cur_count = 0;

        while(cur == s[i]){
            cur_count++;
            i++;

        }

        cur = s[i];

        for(int j = cur_count; j >= 1; j--){
            rst += j;
        }
        
    }

    return rst;
}


int main(){
    string s1 = "aaaba";
    cout << countLetters(s1) << endl;
}