#include "../common_headers.h"

string solution(string s){

    string rst = "";
    int num = stoi(s);
    unordered_map<int, char> map;
    map[0] = 'O';
    map[1] = 'I';
    map[10] = 'A';
    map[11] = 'B';
    map[12] = 'C';
    map[13] = 'D';
    map[14] = 'E';
    map[15] = 'F';
    
    while(num > 0){
        int rem = num % 16;
        if(rem > 1 && rem <=9) return "ERROR";
        else rst = map[rem] + rst;
        num = num / 16;
    }

    return rst;
}


int main(){
    cout << solution("257") << endl;
    cout << solution("3") << endl;
}