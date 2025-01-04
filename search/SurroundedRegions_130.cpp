// DFS recursive
void solve(vector<vector<char>>& board) {
    
    for(int i =0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1)
            helper(board, i, j);
        }
    }
    
    for(int i =0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if(board[i][j] == 'M') board[i][j] = 'O';
        }
    }
}

void helper(vector<vector<char>>& board, int i, int j){
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == 'M') return;
    board[i][j] = 'M';
    helper(board, i+1, j);
    helper(board, i-1, j);
    helper(board, i, j+1);
    helper(board, i, j-1);
}