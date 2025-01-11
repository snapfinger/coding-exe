#include "../common_headers.h"

// Given two vectors of strings, find the difference of the two
// Preserve the original order in the output diff
// list1 = ["3", "4", "3", "4"]
// list2 = ["5"，"8"，"3", "1"]
// output: ["4", "3", "4"]
 
 vector<string> get_diff(vector<string>& input1, vector<string>& input2){
    unordered_map<string, int> m;

    for(auto ele: input2){
        m[ele]++;
    }

    vector<string> rst;

    for(auto str: input1){
        if(m[str] > 0){
            m[str]--;
        }else{
            rst.push_back(str);
        }
    }

    return rst;

 }


 int main(){
    vector<string> v1 = {"3", "4", "3", "4"};
    vector<string> v2 = {"5", "8", "3", "1"};
    auto rst = get_diff(v1, v2);
    for(auto e: rst){
        cout << e << " ";
    }
    cout << endl;

 }