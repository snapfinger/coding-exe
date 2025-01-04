
// Sol1 : DFS recursive
// TC: O(mn), m:#row, n:#col
// SC: O(mn) (stack memory)
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int ori_color = image[sr][sc];
    helper(image, sr, sc, color, ori_color);
    return image;
}

void helper(vector<vector<int>>& image, int sr, int sc, int color, int ori_color){
    if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != ori_color || image[sr][sc] == color) return;
    image[sr][sc] = color;
    helper(image, sr+1, sc, color, ori_color);
    helper(image, sr-1, sc, color, ori_color);
    helper(image, sr, sc+1, color, ori_color);
    helper(image, sr, sc-1, color, ori_color);
}\


// Sol 2: DFS iterative with a stack
// TC: O(mn)
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    stack<pair<int, int>> st;
    int ori_color = image[sr][sc];
    st.push({sr, sc});
    while(!st.empty()){
        pair<int, int> cur = st.top();
        int cur_i = cur.first;
        int cur_j = cur.second;
        st.pop();
        
        if(cur_i < 0 || cur_i >= image.size() || cur_j < 0 || cur_j >= image[0].size() || image[cur_i][cur_j] != ori_color || image[cur_i][cur_j] == color) continue;
        
        image[cur_i][cur_j] = color;
        
        st.push({cur_i+1, cur_j});
        st.push({cur_i-1, cur_j});
        st.push({cur_i, cur_j+1});
        st.push({cur_i, cur_j-1});
    }
    
    return image;
}


// BFS with a queue
// TC: O(mn)
// SC: O(mn)
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int, int>> q;
    int ori_color = image[sr][sc];
    q.push({sr, sc});
    while(!q.empty()){
        pair<int, int> cur = q.front();
        int cur_i = cur.first;
        int cur_j = cur.second;
        q.pop();
        
        if(cur_i < 0 || cur_i >= image.size() || cur_j < 0 || cur_j >= image[0].size() || image[cur_i][cur_j] != ori_color || image[cur_i][cur_j] == color) continue;
        
        image[cur_i][cur_j] = color;
        
        q.push({cur_i+1, cur_j});
        q.push({cur_i-1, cur_j});
        q.push({cur_i, cur_j+1});
        q.push({cur_i, cur_j-1});
    }
    
    return image;
}