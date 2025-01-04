// Sol 2
// use STL reverse function and XOR operator
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    vector<vector<int>> image2 = image;
    cout << image[0][1] << endl;
    for(auto &v: image2){
        reverse(v.begin(), v.end());
        for(auto &e: v){
            e ^= 1;
        }
    }
    cout << image[0][1] << endl;
    return image2;
}


// Sol 1
// my sol
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int n = image.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            int tmp = image[i][j];
            image[i][j] = image[i][n-1-j];
            image[i][n-1-j] = tmp;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            image[i][j] = 1 - image[i][j];
        }
    }
    
    return image;
}