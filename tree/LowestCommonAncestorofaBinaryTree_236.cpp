#include "../common_headers.h"
// TC: O(n)
// SC: O(h)

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left != nullptr && right != nullptr) return root;
    else if(left != nullptr) return left;
    else return right;
}