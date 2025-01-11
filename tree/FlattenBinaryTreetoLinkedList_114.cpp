#include "../common_headers.h"

// iterative dfs 
// TC: O(n)
// SC: O(h)
void flatten(TreeNode* root) {
    if(root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    
    while(!st.empty()){
        auto cur = st.top(); st.pop();
        if(cur->right != nullptr) st.push(cur -> right);
        if(cur->left != nullptr) st.push(cur -> left);

        if(!st.empty()) cur -> right = st.top();

        cur->left = nullptr;
        
    }

}