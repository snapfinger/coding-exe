#include "../common_headers.h"

// dfs
// TC: O(n)
// SC: O(h) 
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return root;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        auto cur = st.top(); st.pop();
        TreeNode* tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
        if(cur->left != nullptr) st.push(cur->left);
        if(cur->right != nullptr) st.push(cur->right);

    }

    return root;
}