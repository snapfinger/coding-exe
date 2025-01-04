#include "../common_headers"


vector<int> conv1d(vector<int>&a, vector<int>& b){
    // assume a is shorter
    if(a.size() > b.size()){
        vector<int> tmp = a;
        a = b;
        b = tmp;
    }

    vector<int> rst;
    reverse(a.begin(), a.end());

    


}

int main(){

}