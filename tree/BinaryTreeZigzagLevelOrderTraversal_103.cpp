#include "../common_headers.h"

// sol 2: recursive dfs
// TC: O(n)
// SC: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> rst;
    helper(rst, 0, root);
    
    return rst;
}

void helper(vector<vector<int>>& rst, int level, TreeNode* root){
    if(root == nullptr) return;
    if(rst.size() <= level) rst.push_back({});
    
    if(level % 2 == 0) rst[level].push_back(root->val);
    else rst[level].insert(rst[level].begin(), root->val);
    
    helper(rst, level+1, root->left);
    helper(rst, level+1, root->right);
    
}


// sol 1: 1 queue and 1 flag var
// TC: O(n)
// SC: O(n)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> rst;
    if(root == nullptr) return rst;
    queue<TreeNode*> q;
    q.push(root);
    bool isleft2right = true;
    while(!q.empty()){
        int cur_size = q.size();
        vector<int> onelevel(cur_size, 0);
        for(int i = 0; i < cur_size; i++){
            auto cur_node = q.front(); q.pop();
            if(isleft2right) onelevel[i] = cur_node->val;
            else onelevel[cur_size-1-i] = cur_node->val;
            if(cur_node->left) q.push(cur_node->left);
            if(cur_node->right) q.push(cur_node->right);
        }
        
        rst.push_back(onelevel);
        isleft2right = !isleft2right;
    }    
    
    return rst;
}