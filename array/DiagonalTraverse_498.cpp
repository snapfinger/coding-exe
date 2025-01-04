#include "../common_headers.h"

// Time: O(m*n)
// Space: O(1)
vector<int> findDiagonalOrder1(vector<vector<int>>& mat) {
    vector<int> rst;
    int M = mat.size(), N = mat[0].size();
    int r = 0, c = 0;
    for(int i = 0; i < M*N; i++){
        rst.push_back(mat[r][c]);
        if((r + c) % 2 == 0){
            if(c == N - 1) r++;
            else if(r == 0) c++;
            else{
                r--; c++;
            }
        }else{
            if(r == M - 1) c++; 
            else if(c == 0) r++;
            else{
                r++; c--;
            }
        }
    }
    return rst;
}

// Time: O((m+n)^2)
// Space: O(1)
vector<int> findDiagonalOrder0(vector<vector<int>>& mat) {
    vector<int> rst;
    int M = mat.size();
    int N = mat[0].size();
    for(int sum = 0; sum <= M + N - 2; sum++){
        for(int x = 0; x <= sum; x++){
            int i = x;
            int j = sum - i;
            if(sum % 2 == 0) swap(i, j);
            
            if(i >= M || j >= N) continue;
            
            rst.push_back(mat[i][j]);
        }
    }
    return rst;
}


vector<int> findDiagonalOrder_noTurn(vector<vector<int>>& mat){
    vector<int> rst;
    int M = mat.size(), N = mat[0].size();
    for(int s = 0; s <= M + N - 2; s++){
        for(int r = min(s, M - 1); r >= 0; r--){
            int c = s - r;
            if(c > N - 1) continue;
            rst.push_back(mat[r][c]);
        }
    }

    return rst;
}


int main(){
    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    vector<int> rst = findDiagonalOrder_noTurn(mat1);

    for(auto v: rst){
        cout << v << " ";
    }
    cout << endl;

}