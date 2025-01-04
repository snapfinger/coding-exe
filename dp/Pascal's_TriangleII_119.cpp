#include "../common_headers.h" 
 
// TC: O(n^2)
// SC: O(n)
vector<int> getRow2(int rowIndex) {
    vector<int> rst(rowIndex+1, 0);
    rst[0] = 1;
    for(int i=1; i<=rowIndex; i++){
        for(int j=i; j>=1; j--){
            rst[j] += rst[j-1];
        }
    }
    return rst;
}


// TC: O(n^2)
// SC: O(n^2)
 vector<int> getRow1(int rowIndex) {
    if(rowIndex == 0) return vector<int>{1};
    if(rowIndex == 1) return vector<int>{1, 1};
    vector<vector<int>> all(rowIndex+1, vector<int>(rowIndex+1, 1));
    for(int i = 2; i <= rowIndex; i++){
        for(int j=1; j < i; j++){
            all[i][j] = all[i-1][j-1] + all[i-1][j];
        }
    }
    return all[rowIndex];
}