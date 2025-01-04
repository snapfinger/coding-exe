#include "../common_headers.h"

int solution(int x){

    if(x <= 1) return 0;

    int prev2 = 0, prev1 = 1, cur, cur2;

    while(prev1 + prev2 < x){
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    cur2 = prev1 + prev2;

    return cur2 - x < x - cur ? cur2 - x: x - cur;
}


int main(){
    // cout << solution(15) << endl;
    // cout << solution(13) << endl;
    // cout << solution(1) << endl;
    // cout << solution(4) << endl;
    cout << stoi("26") << endl;
}