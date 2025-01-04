
// Sol 1: BFS
// TC: O(n)
// SC: O(n)
vector<int> largestValues(TreeNode* root) {
    vector<int> rst;
    if(root == nullptr) return rst;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int max = INT_MIN;
        for(int i = 0; i < n; i++){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->val > max) max = cur->val;
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
        }
        rst.push_back(max);
    }
    return rst;
}