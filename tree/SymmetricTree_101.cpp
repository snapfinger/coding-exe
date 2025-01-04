#include "../common_headers.h"


// Sol 2: iterative with 1 queue, this also works for 1 stack
// TC: O(n)
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root); q.push(root);
    while(!q.empty()){
        TreeNode* cur1 = q.front();
        q.pop();
        TreeNode* cur2 = q.front();
        q.pop();
        if(cur1 == nullptr && cur2 == nullptr){
            continue;
        }else if(cur1 == nullptr || cur2 == nullptr){
            return false;
        }else if(cur1->val != cur2->val){
            return false;
        }
        q.push(cur1->left); q.push(cur2->right); 
        q.push(cur1->right); q.push(cur2->left);
    }
    return true;
}

// Sol 1: recursion
// TC: O(n)
// SC: O(n) (recursion stack, worst case （unbalanced tree))
bool isSymmetric(TreeNode* root) {
    return dfsHelper(root->left, root->right);
}

bool dfsHelper(TreeNode* left, TreeNode* right){
    
    if (left == nullptr && right == nullptr) return true;
    else if(left == nullptr || right == nullptr) return false;
    else if(left->val != right->val) return false;
    else  
        return dfsHelper(left->left, right->right) && dfsHelper(left->right, right->left);
}