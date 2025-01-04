#include "../common_headers.h"


 vector<int> transformArray(vector<int>& arr){
    if(arr.size() <= 2) return arr;

    int n = arr.size();
    vector<int> arr2 = arr;

    do{
        arr = arr2;
        
        for(int i=1; i<arr2.size()-1; i++){
            if((arr[i] < arr[i-1]) && (arr[i] < arr[i+1])){
                arr2[i] = arr[i] + 1;
            }else if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
                arr2[i] = arr[i] - 1;
            }else{
                arr2[i] = arr[i];
            }
        }
    }while(arr != arr2);

    return arr2;

}


int main(){
    vector<int> a1 = {6, 2, 3, 4};
    transformArray(a1);
}